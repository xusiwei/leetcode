#include <string.h>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

#include <iostream>
#include <stdio.h>
using namespace std;

#ifdef DEBUG
#define trace printf
#else
#define trace
#endif

struct Trie 
{
    const static int DEGREE = 256;
    struct Node {
        char  value;
        int   count;
        int   depth;
        Node* parent;
        Node* child[DEGREE];
        
        Node(char v, int c, int d, Node* p) : value(v), count(c), depth(d), parent(p)
                 { memset(child, 0, sizeof(child)); dump(); }
        void dump() { trace("%p: {value: %c, count: %d, depth: %d, parent: %p}\n", this, value, count, depth, parent); }
    };
    
    Node* root;
    
    // for most commmon
    int   maxCount;
    Node* mostCommon;
    
    // for longest common node.
    int   maxDepth;
    Node* longestCommon;
    
    Trie() : root(new Node('#', 0, 0, NULL)), maxCount(0), mostCommon(NULL), maxDepth(0), longestCommon(NULL) {}
    
    void add(string word) {
        Node* p = root;
        //p->count++;
        for(int i = 0; i < word.length(); ++i) {
            // add word[i] to level i, increment the `count` of each node on the word path.
            char c = word[i];
            if(!p->child[c]) {
                p->child[c] = new Node(c, 1, p->depth+1, p);
            }
            else {
                Node* n = p->child[c];
                n->count++;
                if(n->depth > maxDepth) {
                    trace("update longest common node: %p, %d, %c, %s\n", n, i, c, getStr(n).c_str());
                    maxDepth = n->depth;
                    longestCommon = n;
                }
            }
            
            Node* n = p->child[c];
            if(n->count >= maxCount) {
                trace("# update most common node: %p, %d, %c, %s\n", n, n->count, n->value, getStr(n).c_str());
                maxCount = n->count;
                mostCommon  = n;
            }
            
            p = p->child[c];
        }
    }
    
    string getStr(Node* n) {
        string res;
        while(n != root) {
            res = n->value + res;
            n = n->parent;
        }
        return res;
    }
    
    void dump() {
        queue<Node*> nq;
        nq.push(root);
        while(!nq.empty()) {
            Node* p = nq.front(); nq.pop();

            string s = getStr(p);
            trace("%s: %d\n", s.c_str(), p->count);
            
            for(int i = 0; i < DEGREE; ++i) {
                if(p->child[i]) nq.push(p->child[i]);
            }
        }
        trace("Most Common Prefix: %s @ %p\n", mostCommonPrefix().c_str(), mostCommon);
        trace("Longest Common Prefix: %s @ %p\n", longestCommonPrefix().c_str(), longestCommon);
    }
    
    string mostCommonPrefix() { return getStr(mostCommon); }
    
    string longestCommonPrefix() { return getStr(longestCommon); }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t = new Trie();
        
        for(int i = 0; i < strs.size(); ++i) {
            t->add(strs[i]);
        }
        t->dump();
        
        return t->longestCommonPrefix();
    }
};

int main()
{
    string s;
    vector<string> strs;
    
    while(cin >> s) {
        strs.push_back(s);
    }
    
    cout << "Longest Common Prefix: " << Solution().longestCommonPrefix(strs) << endl;
}
