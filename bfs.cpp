#include <iostream>
#include <cstring>

using namespace std;
using PII = pair<int, int>;

const int N = 110;

int n, m;
int maze[N][N], dis[N][N];
PII que[N * N];

int bfs()
{
    memset(dis, 0xff, sizeof(dis));
    dis[0][0] = 0;

    int hh = 0, tt = 0;
    que[0] = {0, 0};

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (hh <= tt) {
        auto t = que[hh ++];
        for (int i = 0; i < 4; ++ i) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && y >= 0 && x < n && y < m && dis[x][y] == -1 && maze[x][y] == 0) {
                dis[x][y] = dis[t.first][t.second] + 1;
                que[ ++ tt] = {x, y};
            }
        }
    }
    return dis[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            cin >> maze[i][j];
        }
    }

    cout << bfs() << endl;

    return 0;
}


