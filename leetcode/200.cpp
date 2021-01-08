#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace  std;

// 方法一 dfs 

class Solution {
public:
    vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};// 按照上下左右的方向
    bool st[310][310];

    void dfs(int x, int y, vector<vector<char>>& g, int m, int n)
    {
        st[x][y] = 1;
        for (int i = 0; i < 4; ++ i) {
            int ne_x = dir[i].first + x, ne_y = dir[i].second + y;
            if (ne_x >= 0 && ne_x < m && ne_y >= 0 && ne_y < n && g[x][y] == '1' && st[ne_x][ne_y] == 0) {
                dfs(ne_x, ne_y, g, m, n);
            }
        }
    }

    int numIslands(vector<vector<char>>& g) {
        memset(st, 0, sizeof(st));

        int res = 0;
        // m是纵高，n是长度;
        int m = g.size(), n = g[0].size();
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (!st[i][j] && g[i][j] == '1') {
                    dfs(i, j, g, m, n);
                    ++ res;
                }
            }
        }
        return res;
    }
};


// 方法2

class Solut {
public:
    vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};// 按照上下左右的方向
    bool st[310][310];
    queue<pair<int, int>> que;

    void bfs(int x, int y, vector<vector<char>>& g, int m, int n)
    { 
        st[x][y] = 1;
        que.push({x, y});
        while (!que.empty()) {
            auto c = que.front();
            que.pop();
            for (int i = 0; i < 4; ++ i) {
                int ne_x = c.first + dir[i].first, ne_y = c.second + dir[i].second;
                if (ne_x >= 0 && ne_x < m && ne_y >= 0 && ne_y < n && g[ne_x][ne_y] == '1' && st[ne_x][ne_y] == 0) {
                    st[ne_x][ne_y] = 1;
                    que.push({ne_x, ne_y});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& g) {
        memset(st, 0, sizeof(st));
        int res = 0;
        // m是纵高，n是长度;
        int m = g.size(), n = g[0].size();
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (!st[i][j] && g[i][j] == '1') {
                    bfs(i, j, g, m, n);
                    ++ res;
                }
            }
        }
        return res;
    }
};


