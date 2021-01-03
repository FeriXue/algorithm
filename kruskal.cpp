#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

struct edge {
    int a = 0, b = 0, c = 0;
} edges[M];

int father[N];

int n, m;

int find(int x)
{
    if (father[x] != x) {
        father[x] = find(father[x]);
    }
    return father[x];
}

int main()
{
    cin >> n >> m;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < m; ++ i) {
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    sort(edges, edges + m, [](edge a, edge b) ->int {return a.c < b.c;});

    for (int i = 1; i <= n; ++ i) { // 并查集初始化;
        father[i] = i;
    }

    int res = 0; // 生成的最小生成树的边权值和;
    int cnt = 0;

    for (int i = 0; i < m; ++ i) {
        int a = edges[i].a, b = edges[i].b, c = edges[i].c;
        a = find(a), b = find(b);
        if (a != b) {
            res += c;
            father[a] = b;
            cnt ++;
        }
    }

    if (cnt != n - 1) {
        cout << "impossible" << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}

