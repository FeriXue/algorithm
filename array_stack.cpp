#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int stk[N], tp = -1;

void push(int x)
{
    stk[++ tp] = x;
}

int top()
{
    return stk[tp];
}

void pop()
{
    -- tp;
}

bool empty()
{
    if (tp == -1) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    int m = 0;
    cin >> m;
    string op;
    int x = 0;
    while (m --) {
        cin >> op;
        if (op == "push") {
            cin >> x;
            push(x);
        } else if (op == "pop") {
            pop();
        } else if (op == "empty") {
            if (empty()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (op == "query") {
            cout << top() << endl;
        }
    }
    return 0;
}

