#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    int work(vector<int> s1, vector<int> s2) // 让s1串严格小于s2串
    {
        int res = INT_MAX;
        for (int i = 1; i < 26; ++ i) { // 枚举s2串的最小的字符，找到操作步骤最少的分界点
            int cnt = 0;
            for (int j = i; j < 26; ++ j) {
                cnt += s1[j];
            }
            for (int j = 0; j < i; ++ j) {
                cnt += s2[j];
            }
            res = min(res, cnt);
        }
        return res;
    }

    int minCharacters(string a, string b) {
        vector<int> s1(26), s2(26);
        for (auto &c : a) {
            ++s1[c - 'a'];
        }
        for (auto &c : b) {
            ++s2[c - 'a'];
        }
        int res = INT_MAX;
        int n = a.size(), m = b.size();
        for (int i = 0; i < 26; ++ i) {
            res = min(res, n + m - (s1[i] + s2[i]));
        }
        
        return min(res, min(work(s1, s2), work(s2, s1)));
    }
};
