#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int h[N], value[N], ne[N], now_in;
int que[N];
int d[N]; // 记录有向无环图中每个节点的入度；

int n, m;

void add(int a, int b)
{
    value[now_in] = b;
    ne[now_in] = h[a];
    h[a] = now_in ++;
    ++ d[b];
}

bool topsort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; ++ i) {
        if (!d[i]) {
            que[++ tt] = i;
        }
    }

    while (hh <= tt) {
        int t = que[hh ++];

        for (int i = h[t]; i != -1; i = ne[i]) {
            int next_point = value[i];
            -- d[next_point];
            if (!d[next_point]) {
                que[++ tt] = next_point;
            }
        }
    }

    return tt == n - 1;
}

int main() 
{
    memset(h, 0xff, sizeof(h));

    cin >> n >> m;
    int a = 0, b = 0;
    for (int i = 0; i < m; ++ i) {
        cin >> a >> b;
        add(a, b);
    }

    if (topsort()) {
        for (int i = 0; i < n; ++ i) {
            cout << que[i] << " ";
        }
        cout << endl;

    } else {
        cout << -1 << endl;
    }

    return 0;
}
