#include <iostream>

using namespace std;

const int N = 210, INF = 1e9;

int g[N][N];

int n, m, Q;

void floyd()
{
    for (int k = 1; k <= n; ++ k) {
        for (int i = 1; i <= n; ++ i) {
            for (int j = 1; j <= n; ++ j) {
                g[i][j] = min (g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> Q;

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j<= n; ++ j) {
            if (i == j) {
                g[i][j] = 0;
            } else {
                g[i][j] = INF;
            }
        }
    }

    int a = 0, b = 0, c = 0;
    while (m --) {
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    floyd();

    int x = 0, y = 0;
    while (Q --) {
        cin >> x >> y;
        if (g[x][y] > INF >> 1) {
            cout << "impossible" << endl;
        } else {
            cout << g[x][y] << endl;
        }

    }

    return 0;
}
