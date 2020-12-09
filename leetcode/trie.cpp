#include <string>

using namespace std;

class Trie {
    private:
    int sonn[100010][26], cnt[100010], now_in = 0;
public:
    /** Initialize your data structure here. */
    Trie() = default;
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int father = 0;
        for (decltype(word.size()) i = 0; i < word.size(); ++ i) {
            int u = word[i] - 'a';
            if (!sonn[father][u]) {
                sonn[father][u] =  ++ now_in;
            }
            father = sonn[father][u];
        }
        ++ cnt[father];
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int father = 0;
        for (decltype(word.size()) i = 0; i < word.size(); ++ i) {
            int u = word[i] - 'a';
            if (!sonn[father][u]) {
                return false;
            } else {
                father = sonn[father][u];
            }
        }
        if (cnt[father] != 0) {
            return true;
        } else {
            return false;
        }
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int father = 0;
        for (decltype(prefix.size()) i = 0; i < prefix.size(); ++ i) {
            int u = prefix[i] - 'a';
            if (!sonn[father][u]) {
                return false;
            } else {
                father = sonn[father][u];
            }
        }
        return true;
    }
};

