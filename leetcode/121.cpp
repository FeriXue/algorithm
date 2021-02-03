#include <iostream>
#include <vector>

using namespace std;

// 直接暴力枚举会超时；
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = (int)p.size();
        int res = 0;
        for (int i = 0; i < n; ++ i) {
            for (int j = i + 1; j < n; ++ j) {
                res = max(res, p[j] - p[i]);
            }
        }
        return res > 0 ? res : 0;
    }
};

// dp;
class Solutio {
public:
    int maxProfit(vector<int>& p) {
        int n = (int)p.size();
        int mv = p[0];
        vector<int> f;
        f.push_back(0);
        for (int i = 1; i < n; ++ i) {
            f.push_back(max(f[i - 1], p[i] - mv));
            mv = min(mv, p[i]);
        }

        return f[n - 1];
    }
};
