#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 1e4 + 10;

struct {
    int a = 0;
    int b = 0;
    int w = 0;
} edge[M];

int dist[N], backup[N];
int n, m, k;

int bellman_ford()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    for (int i = 0; i < k; ++ i) {
        memcpy(backup, dist, sizeof(dist));
        for (int j = 1; j <= m; ++ j) {
            int a = edge[j].a, b = edge[j].b, w = edge[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    if (dist[n] > 0x3f3f3f3f >> 1) {
        return -1;
    }
    return dist[n];
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++ i) {
        cin >> edge[i].a >> edge[i].b >> edge[i].w;
    }

    int t = bellman_ford();
    if (t == -1) {
        cout << "impossible" << endl;
    } else {
        cout << t << endl;
    }
    return 0;
}

