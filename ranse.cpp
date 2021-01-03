#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int h[N], value[M], ne[M], now_in;
int color[N];

int n, m;

void add(int a, int b)
{
    value[now_in] = b;
    ne[now_in] = h[a];
    h[a] = now_in ++;
}

bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int next_point = value[i];
        if (!color[next_point]) {
            if (!dfs(next_point, 3 - c)) {
                return false;
            }
        } else if (color[next_point] == c) {
            return false;
        }
    }
    return true;
}

int main()
{
    memset(h, 0xff, sizeof(h));
    
    cin >> n >> m;
    int a = 0, b = 0;
    while (m --) {
        cin >> a >> b; 
        add(a, b);
        add(b, a);
    }

    bool flg = 1;
    for (int i = 1; i <= n; ++ i) {
        if (!color[i]) {
            if (!dfs(i, 1)) {
                flg = 0;
                break;
            }
        }
    }
    
    if (!flg) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}

