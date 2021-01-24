#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool check(string time, string str)
    {
        for (int i = 0; i < 5; ++ i) {
            if (time[i] == str[i] || time[i] == '?') {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    string maximumTime(string time) {
        string res;
        for (int i = 23; i >= 0; -- i) {
            for (int j = 59; j >= 0; -- j) {
                char str[15];
                sprintf(str, "%02d:%02d", i, j);
                if (check(time, str)) {
                    return str;
                }       
            }
        }
        return "";
    }
};
