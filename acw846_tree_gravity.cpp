#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int h[N], value[M], ne[M], now_in;
bool st[N];

int n;
int ans = N;

void add(int a, int b)
{
    value[now_in] = b;
    ne[now_in] = h[a];
    h[a] = now_in ++;
}

int dfs(int u) // 返回每一颗子树的大小
{
    st[u] = 1;
    
    int sum = 1; // 当前子树的大小，因为至少有一个节点，所以从1开始；
    int res = 0; // 当删除掉当前节点后，剩下的所有联通块中最多的节点数；

    for (int i = h[u]; i != -1; i = ne[i]) {
        int next_point = value[i];
        if (!st[next_point]) {
            int s = dfs(next_point);
            res = max(res, s); // 返回的子树也是一个联通块 , 其实相当于遍历了所有的联通块，就相当于遍历着删除了每一个点
            sum += s; // 返回的子树是当前节点的一个子树；
        }
    }

    res = max(res, n - sum); // 在这里会得到删除掉该节点后最大的联通块节点数;
    ans = min(ans, res);

    return sum;
}

int main()
{
    memset(h, 0xff, sizeof(h));
    cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < n - 1; ++ i) {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    
    dfs(1);
    
    cout << ans << endl;
    return 0;
}

