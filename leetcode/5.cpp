#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        const int N = 1e3 + 10;
        int f[N][N];
        memset(f, 0, sizeof(f));

        int n = s.size();
        for (int len = 0; len < n; ++ len) {
            for (int i = 0; i + len < n; ++ i) {
                int j = i + len;
                if (len == 0) {
                    f[i][j] = 1;
                } else if (len == 1) {
                    if (s[i] == s[j]) {
                        f[i][j] = 2;
                    }
                } else {
                    if (f[i + 1][j - 1] && s[i] == s[j]) {
                        f[i][j] = f[i + 1][j - 1] + 2;
                    }
                }
            }
        }
        int res = 0;
        int l = -1, r = -1;
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (f[i][j] > res) {
                    l = i;
                    r = j;
                    res = f[i][j];
                }
            }
        }
        string ans(s.begin() + l, s.begin() + r + 1);
        return ans;
    }
};
