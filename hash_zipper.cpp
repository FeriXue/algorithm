#include <iostream>
#include <cstring>

using namespace std;

const int N = 100003;

int h[N];
int value[N], ne[N], now_in;

void init()
{
    memset(h, -1, sizeof(h));
}

void insert(int x)
{
    int t = 0;
    if (x >= 0) {
        t = x % N;
    } else {
        t = (-x) % N;
    }

    value[now_in] = x;
    ne[now_in] = h[t];
    h[t] = now_in ++;
}

bool find(int x)
{
    int t = 0;       
    if (x >= 0) {    
        t = x % N;   
    } else {         
        t = (-x) % N;
    }                

    for (int i = h[t]; i != -1; i = ne[i]) {
        if (value[i] == x) {
            return true;
        }
    }
    return false;
}

int main()
{
    init();
    int n = 0;
    cin >> n;
    string op;
    int x = 0;
    while (n --) {
        cin >> op;
        if(op == "I") {
            cin >> x;
            insert(x);
        } else if (op == "Q") {
            cin >> x;
            if (find(x)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    } 
    return 0;
}

