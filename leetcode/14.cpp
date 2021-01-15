#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        if (s.size() == 0) {
            return {""};
        }
        string res = *s.begin();
        
        for (int i = 0; i < (int)s.size(); ++ i) {
            auto t = s[i].begin();
            auto rest = res.begin();
            while (rest != res.end() && t != s[i].end()) {
                if (*rest == *t) {
                    ++ t, ++ rest;
                } else {
                    break;
                }
            }
            res.erase(rest - res.begin(), res.end() - rest);
        }
        return res;
    }
};
