#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& p) {
        if (p.empty()) {
            return 0;
        } 
        int n = (int)p.size();
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -p[0];

        for (int i = 1; i < n; ++ i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - p[i]);
            f[i][1] = f[i - 1][0] + p[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }

        return max(f[n - 1][1], f[n - 1][2]);

    }
};
