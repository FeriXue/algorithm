#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        const int N = 1e4  + 10;
        int stk[N], tp = -1;
        for (decltype(s.size()) i = 0; i < s.size(); ++ i) {
            if (s[i] == '(' || s[i] == '['|| s[i] == '{') {
                stk[++ tp] = s[i];
            } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (tp == -1) {
                    return false;
                } else {
                    if (s[i] == ')') {
                        if (stk[tp] == '(') {
                            -- tp;
                        } else {
                            break;
                        }
                    }
                    if (s[i] == ']') {
                        if (stk[tp] == '[') {
                            -- tp;
                        } else {
                            break;
                        }
                    }
                    if (s[i] == '}') {
                        if (stk[tp] == '{') {
                            -- tp;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        if (tp == -1) {
            return true;
        } else {
            return false;
        }
    }
};


