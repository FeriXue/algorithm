#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = N * 31;

int son[M][2], now_in;
int a[N];

void insert_num(int x)
{
    int father = 0;
    for (int i = 30; i >= 0; -- i) {
        int u = x >> i & 1;
        if (!son[father][u]) {
            son[father][u] = ++ now_in;
        }
        father = son[father][u];
    }
}

int query_num(int x)
{
    int father = 0;
    int max_now = 0;
    for (int i = 30; i >= 0; -- i) {
        int u = x >> i & 1;
        if (son[father][!u]) {
            father = son[father][!u];
            max_now = max_now * 2 + !u;
        } else {
            father = son[father][u];
            max_now = max_now * 2 + u;
        }
    }

    return max_now;
}

int main()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    
    int max_num = 0;
    // 暴力遍历的做法
    /* for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < i; ++ j) {

        }
    } */

    for (int i = 0; i < n; ++ i) {
        insert_num(a[i]);
        int t = query_num(a[i]);
        max_num = max(max_num, t ^ a[i]);
    }

    cout << max_num << endl;

    return 0;
}
