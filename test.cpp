#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;

int g[N][N];
int dist[N];
bool st[N];
int n, m;

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    for (int i = 1; i <= n; ++ i) {
        int t = -1;
        for (int j = 1; j <= n; ++ j) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }

        st[t] = 1;

        for (int j = 1; j <= n; ++ j) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }

    if (dist[n] == 0x3f3f3f3f) {
        return -1;
    } else {
        return dist[n];
    }
}

int main()
{
    memset(g, 0x3f, sizeof(g));

    cin >> n >> m;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < m; ++ i) {
        cin >> a >> b >> c;
        g[a][b] = min (g[a][b], c);
    }

    cout << dijkstra() << endl;

    return 0;
}
