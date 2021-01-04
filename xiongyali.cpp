#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 1e5 + 10;

int h[N], value[M], ne[M], now_in;
bool st[N];
int match[N];

int n1, n2, m;

void add(int a, int b)
{
    value[now_in] = b;
    ne[now_in] = h[a];
    h[a] = now_in ++;
}

bool find(int x)
{
    for (int i = h[x]; i != -1; i = ne[i]) {
        int next_point = value[i];
        if (!st[next_point]) {
            st[next_point] = 1;
            if (match[next_point] == 0 || find(match[next_point])) {
                match[next_point] = x;
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    memset(h, 0xff, sizeof(h));
    cin >> n1 >> n2 >> m;

    int a = 0, b = 0;
    while (m --) {
        cin >> a >> b;
        add(a, b);
    }

    int res = 0; // 二分图的最大匹配数;
    for (int i = 1; i <= n1; ++ i) {
        memset(st, 0, sizeof(st));
        if (find(i)) {
            ++ res;
        }
    }

    cout << res << endl;

    return 0;
}

