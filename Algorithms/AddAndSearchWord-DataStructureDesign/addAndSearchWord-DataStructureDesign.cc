/*
copyright xu(xusiwei1236@163.com), all right reserved.

Add and Search Word - Data structure design
============================================

Design a data structure that supports the following two operations:


void addWord(word)
bool search(word)



search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.


For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true



Note:
You may assume that all words are consist of lowercase letters a-z.


click to show hint.

You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
*/
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class WordDictionary {
public:
    struct Node {
        int count;
        Node* children[26];
        Node() : count(0) {
            memset(children, 0, sizeof(children));
        }
    };

    WordDictionary() {
        root = new Node();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        Node* p = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            Node** q = &p->children[c-'a'];
            if (!*q) {
                *q = new Node();
            }
            p = *q;
        }
        p->count++;
    }

    void backtrack(const string& target, bool& result, Node* curr, string& word) {
        const int k = word.length();
        if (k == target.length() && curr->count) {
            result = true;
            return;
        }

        if (k < target.length()) {
            const char c = target[k];
            if (c == '.') {
                for (int i = 0; i < 26; i++) {
                    if (curr->children[i]) {
                        word.push_back(i+'a');
                        // cout << "try " << word << endl;
                        backtrack(target, result, curr->children[i], word);
                        word.pop_back();
                    }
                }
            } else {
                if (curr->children[c - 'a']) {
                    word.push_back(c);
                    // cout << "continue " << word << endl;
                    backtrack(target, result, curr->children[c - 'a'], word);
                    word.pop_back();
                }
            }
        }
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string target) {
        string word;
        bool result = false;
        backtrack(target, result, root, word);
        return result;
    }

    void dump(Node* curr, string& word) {
        if (curr->count) {
            cout << word << endl;
        }
        for (int i = 0; i < 26; i++) {
            if (curr->children[i]) {
                word.push_back('a'+i);
                dump(curr->children[i], word);
                word.pop_back();
            }
        }
    }

    void dump() {
        string word;
        cout << "\ndump():\n";
        backdump(root, word);
        cout << endl;
    }
private:
    Node* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(int argc, char* argv[])
{
    WordDictionary dict;
#define addWord(w) cout << "addWord(" << w << ")\n"; dict.addWord(w)
#define search(w) cout << "search(" << w << "): " << (dict.search(w) ? "true\n" : "false\n")

    addWord("bad");
    addWord("dad");
    addWord("mad");
    dict.dump();
    search("pad");
    search("booom");
    search("bad");
    search(".ad");
    search("b..");
    search("...");
    search("..");
    search(".");
    search("b...");
    return 0;
}
