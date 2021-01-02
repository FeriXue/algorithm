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
    int res = 0;

    for (int i = 0; i < n; ++ i) {
        int t = -1;
        for (int j = 1; j <= n; ++ j) {
            if (!(st[j]) && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
        
        if (i && dist[t] == INF) { // 如果不是第一个点并且距离集合最近的点的距离为INF说明没有生成树;
            return INF;
        }
        if (i) {
            res += dist[t]; // 这一步要放在使用t更新其他点的前面，因为可能存在自环并且边权值为负数，可能会自己更新自己；
        }

        st[t] = 1;

        for (int j = 1; j <= n; ++ j) {
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
    for (int i = 0; i < n; ++ i) {
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

