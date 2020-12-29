#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;
int g[N][N]; // 邻接矩阵存储稠密图；
int dist[N]; // 存储朴素dijkstra算法中每个节点到源点的最短路
bool st[N]; // 每个节点的最短路是否确认;
int n, m;

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0; // 起点到起点的距离是1

    for (int i = 1; i <= n; ++ i) { // 循环n次， 每一次循环都可以确定一个点的最短路；
        // 找到还没有确定最短路的节点中距离起点距离最短的节点；
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


// 本题使用朴素dijikstra算法输出节点1到节点n之间的最短路;

int main()
{
    memset(g, 0x3f, sizeof(g)); // 初始化邻接矩阵；

    cin >> n >> m;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < m; ++ i) {
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    cout << dijkstra() << endl;

    return 0;
}

