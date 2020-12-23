#include <iostream>

using namespace std;
using LL = long long;

const int N = 1e6 + 10;

int prime[N], phi[N], cnt;
bool st[N];

LL get_oula(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; ++ i) {
        if (!st[i]) {
            prime[cnt ++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; prime[j] <= n / i; ++ j) {
            st[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                phi[prime[j] * i] = phi[i] * prime[j];
                break;
            }
            phi[prime[j] * i] = phi[i] * (prime[j] - 1);
        }
    }
    LL res = 0;
    for (int i = 1; i <=n; ++ i) {
        res += phi[i];
    }
    return res;
}

int main()
{
    int n = 0;
    cin >> n;
    cout << get_oula(n) << endl;
    return 0;
}

