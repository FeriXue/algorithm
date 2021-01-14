#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res;
        auto i = s.begin(), t = s.begin();
        while(i != s.end()) {
            if (*i == ' ') {
                for (auto j = i - 1; j >= t; -- j) {
                    res += *j;
                }
                res += *i;
                t = ++ i;
            }
            ++ i;
        }
        for (auto j = i - 1; j >= t; -- j) {
            res += *j;
        }
        return res;
    }
};
