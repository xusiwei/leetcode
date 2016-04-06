/*
copyright xu(xusiwei1236@163.com), all right reserved.

Implement Trie (Prefix Tree)
=============================

Implement a trie with insert, search, and startsWith methods.



Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/
#include <string.h>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Trie;

class TrieNode {
    friend class Trie;
    int count;
    TrieNode* children[26];
public:
    // Initialize your data structure here.
    TrieNode() : count(0) {
        memset(children, 0, sizeof(children));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            TrieNode** q = &p->children[c-'a'];
            if (!*q) {
                *q = new TrieNode();
            }
            p = *q;
        }
        p->count++;
    }

    TrieNode* prefix(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!p->children[c-'a']) {
                return NULL;
            }
            p = p->children[c-'a'];
        }
        return p;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = prefix(word);
        return p != NULL && p->count > 0;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string word) {
        return prefix(word) != NULL;
    }

    void backtrack(TrieNode* curr, string& word) {
        if (curr->count) {
            cout << word << endl;
        }
        for (int i = 0; i < 26; i++) {
            if (curr->children[i]) {
                word.push_back('a'+i);
                backtrack(curr->children[i], word);
                word.pop_back();
            }
        }
    }

    void dump() {
        // dfs
        string word;
        backtrack(root, word);

        stack<TrieNode*> s;
        s.push(root);
        while (!s.empty()) {
            TrieNode* p = s.top(); s.pop();
            cout << p << "\t" << p->count << "\t";
            for (int i = 0; i < 26; i++) {
                if (p->children[i]) {
                    s.push(p->children[i]);
                    cout << static_cast<char>('a' + i) << ", ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(int argc, char* argv[])
{
    Trie trie;
    trie.insert("somestring");
    trie.insert("some");
    trie.insert("sometime");
    trie.dump();
    cout << trie.search("some") << endl;
    cout << trie.search("something") << endl;
    cout << trie.startsWith("som") << endl;
    return 0;
}
