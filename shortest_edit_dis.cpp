#include <iostream>

using namespace std;

const int N = 1010;

char a[N], b[N];
int f[N][N];

int n, m;

int main()
{
    cin >> n;
    scanf("%s", a + 1);
    cin >> m;
    scanf("%s", b + 1);

    for (int i = 0; i <= m; ++i) { // 假如字符串a为空，那么要进行的操作就都是增加，增加执行多少次取决于字符串b的长度;
        f[0][i] = i;
    }
    for (int j = 0; j <= n; ++ j) {
        f[j][0] = j;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if (a[i] != b[j]) {
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
            } else {
                f[i][j] = min (f[i][j], f[i - 1][j - 1]);
            }
        }
    }

    cout << f[n][m] << endl;
    return 0;
}

