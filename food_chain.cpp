#include <iostream>                                                                                                                                                                                                                                                                                                          

using namespace std;

const int N = 50010;

int father[N], dis[N]; // d[x]代表的是x点到根节点的距离，因为每个集合初始都只有一个点，所有d[x]被初始化为0；
// 使用dis[N]来表示三个物种之间的关系，因为三个物种之间形成了一个环，所以使用模3等于0来表示和根节点同种类，模3等于1表示吃根节点， 莫三等于2表示被根节点吃
//这里存放的距离并不是物理上节点之间的距离，而是概念上使用这样的距离来表示集合中物种之间的关系； 

int find(int x)
{
    if (father[x] != x) {
        int t = find(father[x]);
        dis[x] += dis[father[x]];
        father[x] = t;
    }
    return father[x];
}

int find_(int x)
{
    if (father[x] != x) {
        dis[x] = dis[x] + dis[father[x]]; // 这里的dis[father[x]]表示的是旧的根节点到新的根节点之间的距离
        father[x] = find(father[x]);
    }
    return father[x];
}


int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        father[i] = i;
    }
    int fake = 0;
    while (m --) {
        int d = 0, x = 0, y = 0;
        scanf("%d%d%d", &d, &x, &y);
        if (x > n || y > n) {
            ++ fake;
        } else if (d == 1) {
            // 首先判断这句话是不是假话
            int father_x = find(x), father_y = find(y);
            if (father_x == father_y && (dis[x] - dis[y]) % 3) {
                ++ fake;
            } else if (father_x != father_y) {
                father[father_x] = father_y;
                dis[father_x] = dis[y] - dis[x];
            }
        } else if (d == 2) {
            int father_x = find(x), father_y = find(y);
            if (father_x == father_y && (dis[x] - dis[y] - 1) % 3) {
                ++ fake;
            } else if (father_x != father_y) {
                father[father_x] = father_y;
                dis[father_x] = dis[y] + 1 - dis[x];
            }
        }
    }
    cout << fake << endl;
    return 0;
}

