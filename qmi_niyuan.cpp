#include <iostream>

using namespace std;
using LL = long long;

int get_qmi(int a, int k, int p)
{
    LL res = 1;
    while (k) {
        if (k & 1) {
            res = res * a % p;
        }
        k >>= 1;
        a = (LL)a * a % p;
    }

    return res;
}

int main()
{
    int n = 0;
    cin >> n;
    int a = 0, k = 0, p = 0;
    while (n --) {
        cin >> a >> p;
        k = p - 2;
        if (a % p == 0) {
            cout << "impossible" << endl;
        } else {
            cout << get_qmi(a, k, p) << endl;
        }
    }
    return 0;
}

