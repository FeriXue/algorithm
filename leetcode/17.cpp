#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public: 
    vector<string> res;

    void dfs(string s, int n, string temp, unordered_map<char, string> hash)
    {
        if (n == s.size()) {
            res.push_back(temp);
            return;
        }
        auto t = hash.find(s[n]) -> second;
        for (int i = 0; i < t.size(); ++ i) {
            temp += t[i];
            dfs(s, n + 1, temp, hash);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string s) {
        
        unordered_map<char, string> hash{{'1', ""}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        if (s == "") {
            return res;
        }
        dfs(s, 0, "", hash);
        return res;
    }
};
