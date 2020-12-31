#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int h[N], value[N], ne[N], w[N], now_in;
int dist[N];
bool st[N];

int n, m;

void add(int a, int b, int c)
{
    value[now_in] = b;
    w[now_in] = c;
    ne[now_in] = h[a];
    h[a] = now_in ++;
}

int spfa()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = 1;

    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = 0;
        
        for (int i = h[t]; i != -1; i = ne[i]) {
            int next_point = value[i];
            if (dist[next_point] > dist[t] + w[i]) {
                dist[next_point] = dist[t] + w[i];
                if (!st[next_point]) {
                    q.push(next_point);
                    st[next_point] = 1;
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) {
        return -1;
    }
    return dist[n];
}

int main()
{
    memset(h, 0xff, sizeof(h));
    cin >> n >> m;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < m; ++ i) {
        cin >> a >> b >> c;
        add(a, b, c);
    }

    int t = spfa();
    if (t == -1) {
        cout << "impossible" << endl;
    } else {
        cout << t << endl;
    }

    return 0;
}

