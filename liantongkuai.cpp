#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int father[N], size_liantong[N];

int find(int x)
{
    if (father[x] != x) {
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
        size_liantong[i] = 1;
    }
    string op;
    int a = 0, b = 0;
    while (m --) {
        cin >> op;
        if (op == "C") {
            cin >> a >> b;
            if (find(a) == find(b)) {
                continue;
            }
            size_liantong[find(b)] += size_liantong[a];
            father[find(a)] = find(b);
        } else if (op == "Q1") {
            cin >> a >> b;
            if (find(a) == find(b)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        } else if (op == "Q2") {
            cin >> a;
            cout << size_liantong[find(a)] << endl;
        }
    }
    return 0;
}

