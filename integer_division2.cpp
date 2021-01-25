#include <iostream>

using namespace std;

const int N = 1010, mod = 1e9 + 7;;

int f[N][N];

int n;

int main()
{
    cin >> n;

    f[0][0] = 1;

    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= i; ++ j) {
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod;
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; ++ i) {
        ans = (ans + f[n][i]) % mod;
    }

    cout << ans << endl;
    return 0;
}

