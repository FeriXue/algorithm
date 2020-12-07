#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int stk[N], tp = -1;
int num[N];

int main()
{
    int n = 0;
    cin >> n; // scanf更快写项目可调换
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    for (int i = 0; i < n; ++i) {
        while (tp != -1 && stk[tp] >= num[i]) {
            --tp;
        }
        if (tp != -1) {
            cout << stk[tp] << " "; 
        } else {
            cout << -1 << " ";
        }
        stk[++tp] = num[i];
    }

    return 0;
}

