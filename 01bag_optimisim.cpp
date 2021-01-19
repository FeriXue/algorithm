#include <iostream>

using namespace std;

const int N = 1010;

int v[N], w[N];
// f[i][j] 表示的是从前i个物品中挑选出体积之和不超过j的最大价值是多少
int f[N];

int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; ++ i) { // i值确定表示从i个物品中挑选 物品数已确定
        for (int j = m; j >= v[i]; -- j) { // 当物品数目已确定为i时，确定总体积数值
            f[j] = max(f[j], f[j - v[i]] + w[i]); // 当总物品数是i时，背包的不同大小由小到大对应着能储存的最大价值是多少。
        }
    }
    
    cout << f[m] << endl; // 只输出f[m]的原因是，物品数目一定会停在i == n上，更新后的f数组中存放的就是当物品数目为n时，不同
    //背包体积对应的最大价值是多少。
    return 0;
}

