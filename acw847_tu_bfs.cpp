#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 1e5 + 10;

int h[N], value[N], ne[M], now_in;
int dis[N];
int que[N];
int n, m;

void add(int a, int b)
{
    value[now_in] = b;
    ne[now_in] = h[a];
    h[a] = now_in ++;
}

int bfs()
{
    memset(dis, 0xff, sizeof(dis));
    dis[1] = 0;

    int hh = 0, tt = 0;
    que[0] = 1;

    while (hh <= tt) {
        int t = que[hh ++];

        for (int i = h[t]; i != -1; i = ne[i]) {
            int next_point = value[i];
            if (dis[next_point] == -1) {
                dis[next_point] = dis[t] + 1;
                que[++ tt] = next_point;
            }
        }
    }

    return dis[n];
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
    
    cout << bfs() << endl;

    return 0;
}
