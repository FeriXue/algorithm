#include <iostream>                                                                                                                                                                                                                                                                                                          
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int h[N], value[N], ne[N], w[N], now_in;
int dist[N], cnt[N];
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
    queue<int> q;
    for (int i = 1; i <= n; ++ i) {
        q.push(i);
        st[i] = 1;
    }

    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = 0;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int next_point = value[i];
            if (dist[next_point] > dist[t] + w[i]) {
                dist[next_point] = dist[t] + w[i];
                cnt[next_point] = cnt[t] + 1;
                if (cnt[next_point] >= n) {
                    return true;
                }
                if (!st[next_point]) {
                    q.push(next_point);
                    st[next_point] = 1;
                }
            }
        }
    }

    return false;
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
    if(t) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

