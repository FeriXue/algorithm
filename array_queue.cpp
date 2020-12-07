#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int queuee[N], head = 0, tail = -1;

void push(int x)
{
    queuee[++tail] = x;
}

void pop()
{
    head++;
}

int top()
{
    return queuee[head];
}

bool empty()
{
    if (head <= tail) {
        return 0;
    } else {
        return 1;
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

