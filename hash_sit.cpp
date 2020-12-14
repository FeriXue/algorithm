#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003, nulll = 1e9 + 10;

int h[N];

int find(int x)
{
    int t = 0;
    if (x >= 0) {
        t = x % N;
    } else {
        t = (- x) % N;
    }
    while (h[t] != nulll && h[t] != x) {
        ++ t;
    }

    return t;
}

int main()
{
    memset(h, nulll, sizeof(h));
    int n = 0, x = 0;
    cin >> n;
    string op;
    while (n --) {
        cin >> op >> x;
        int t = find(x);
        if (op == "I") {
            h[t] = x;
        } else if (op == "Q") {
            if (h[t] == nulll) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }

        }
    }
    return 0;
}
