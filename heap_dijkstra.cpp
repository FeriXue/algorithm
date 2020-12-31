#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
using PII = pair<int, int>;

const int N = 1.5e5 + 10;

int h[N], w[N], value[N], ne[N], now_in;
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

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, 1});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distant = t.first;
        if (st[ver]) {
            continue;
        }
        st[ver] = 1;
        for (int i = h[ver]; i != -1; i = ne[i]) {
            int next_point = value[i];
            if (dist[next_point] > distant + w[i]) {
                dist[next_point] = distant + w[i];
                heap.push({dist[next_point], next_point});
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

    cout << dijkstra() << endl;
    return 0;
}
