#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int g[N][N];
int dist[N];
bool st[N];
int n, m;

int prim()
{
    memset(dist, 0x3f, sizeof(dist));

    int res = 0; // 返回最小生成树的权值和;

    for (int i = 0; i < n; ++ i) {
        int t = -1;
        for (int j = 1; j <= n; ++ j) { // 找到不在集合中距离集合最近的点t
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }

        if (i && dist[t] == INF) {
            return INF;
        }

        if (i) {
            res += dist[t];
        }

        st[t] = 1; // 将点t加入集合中;
        for (int j = 1; j <= n; ++ j) { // 使用点t更新其他的点
            dist[j] = min(dist[j], g[t][j]);
        }
    }

    return res;
}

int main()
{
    memset(g, 0x3f, sizeof(g));
    cin >> n >> m;
    int a = 0, b = 0, c = 0;

    while (m --) {
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();

    if (t == INF) {
        cout << "impossible" << endl;
    } else {
        cout << t << endl;
    }
    return 0;
}
