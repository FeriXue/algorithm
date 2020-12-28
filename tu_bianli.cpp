#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;

int h[N], value[N], ne[N], now_in;
bool st[N];

void add(int a, int b) // 添加一条由a指向b的边； 
{
    value[now_in] = b;
    ne[now_in] = h[a];
    h[a] = now_in ++;
}

void dfs(int u)
{
    st[u] = 1;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int next_point = value[i];
        if (!st[next_point]) {
            dfs(next_point);
        }
    }

}

int main()
{
    memset(ne, 0xff, sizeof(ne));
    return 0;
}

