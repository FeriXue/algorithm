#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>> &g, int sx, int sy, vector<vector<bool>> &st, string &s, int k)
    {
        if (g[sx][sy] != s[k]) {
            return false;
        } else if (k == (int)s.size() - 1) {
            return true;
        }
        st[sx][sy] = true;

        vector<pair<int, int>> d{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = g.size(), n = g[0].size();
        bool res = false;
        for (auto &c : d) {
            int nx = sx + c.first, ny = sy + c.second;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !st[nx][ny]) {
                bool flag = dfs(g, nx, ny, st, s, k + 1); // k + 1和++k的区别是++k改变了k的值，而k+1没有
                // 回溯
                if (flag) { // 剪枝
                    res = true;
                    break;
                }
            }
        } 
        st[sx][sy] = false; // 恢复现场
        return res;  
    }
  
    bool exist(vector<vector<char>>& g, string s) { 
        int m = g.size(), n = g[0].size();
        vector<vector<bool>> st(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int flag = dfs(g, i, j, st, s, 0);
                //cout << flag << endl;
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};
