#include <iostream>                                                                                                                                                                                                                                                                                                          
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int value[N], next_[N], head, temp, now_in;

void init()
{
    head = -1;
    //temp = head;
    now_in = 0;
}

void head_insert(int x)
{
    value[now_in] = x;
    next_[now_in] = head;
    head = now_in;
    ++ now_in;
}

/* void tail_insert(int x)
{
    value[now_in] = x;
    next_[now_in] = next_[temp];
    next_[temp] = now_in;
    ++ now_in;
    ++ temp;
} */

void insert_k_x(int k, int x)
{
    value[now_in] = x;
    next_[now_in] = next_[k - 1];
    next_[k - 1] = now_in;
    ++ now_in;
}

void delete_value(int k)
{
    if (k == -1) {
        head = next_[head];
    } else {
        next_[k] = next_[next_[k]];
    }
}

int main()
{
    init();
    int M = 0;
    cin >> M;
    string op;
    int k = 0, x = 0;
    while (M--) {
        cin >> op;
        if (op == "H") {
            cin >> x;
            head_insert(x);
        } else if (op == "D") {
            cin >> k;
            delete_value(k - 1);
        } else {
            cin >> k >> x;
            insert_k_x(k, x);
        }
    }
    for (int i = head; i != -1; i = next_[i]) {
        cout << value[i] << " ";
    }
    cout << endl;

    return 0;
}

