#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (!s.size()) {
            return true;
        }
        auto tb = s.begin(), te = s.end() - 1;

        while (tb < te) {
            while (!isalnum(*tb)) {
                if (tb == s.end()) {
                    return true;
                }
                ++ tb;
            }
            while (!isalnum(*te)) {
                if (te < s.begin()) {
                    return false;
                }
                -- te;
            }
            if (isupper(*tb) && tb != s.end()) {
                *tb = tolower(*tb);
            }
            if (isupper(*te) && te >= s.begin()) {
                *te = tolower(*te);
            }

            if (*tb == *te && tb != s.end() && te >= s.begin()) {
                ++ tb, --te;
            } else {
                return false;
            }

        }
        return true;
    }
};

