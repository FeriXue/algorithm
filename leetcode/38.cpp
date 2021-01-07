#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string find(int x) 
    {
        if (x == 1) {
            return "1";
        }
        string t = find(x - 1);
        string temp;
        int k = 0, st = 0;
        for (int i = 0; i < t.size(); ++ i) {
            if (i == t.size() - 1 || t[i] != t[i + 1]) {
                k = i - st + 1;
                st = i + 1;
                temp += k + 48;
                temp += t[i];
            }
        }
        t = temp;
        return t;
    }
    string countAndSay(int n) {
        string t = find(n);
        return t;
    }
};
