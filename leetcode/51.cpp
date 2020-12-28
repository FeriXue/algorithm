#include <iostream>
#include <string>
#include <vector>


using namespace std;
class Solution {
public:

    const int N = 20;

    void dfs(int u, int n, vector<string> ou, vector<vector<string>> &res, bool *col, bool *dg, bool *udg)
    {
        if (u == n) {
            res.push_back(ou);
            ou.clear();
        }

        for (int i = 0; i < n; ++ i) {
            string ss(n, '.');
            if (!col[i] && !dg[u + i] && !udg[u - i + n - 1]) {
                ss.replace(i, 1, "Q");
                ou.push_back(ss);
                col[i] = dg[u + i] = udg[u - i + n - 1] = 1;
                dfs(u + 1, n, ou, res, col, dg, udg);
                col[i] = dg[u + i] = udg[u - i + n - 1] = 0;
                ou.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> ou;
        bool col[N], dg[N], udg[N];
        for (int i = 0; i < N; ++ i) {
            col[i] = 0, dg[i] = 0, udg[i] = 0;
        }

        dfs(0, n, ou, res, col, dg, udg);
        return res;
    }
};
