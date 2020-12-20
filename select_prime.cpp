#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int prime[N], st[N], cnt;

void se_prime(int n)
{
    // 朴素筛法，时间复杂度为O(nlogn);
   /* for (int i = 2; i <= n; ++ i) {
        if (!st[i]) {
            prime[cnt ++] = i;
        }
        for (int j = i + i; j <= n; j += i) {
            st[j] = 1;
        }
    } */
    // 优化：
    // 不需要将每一个数的倍数删掉只需要将质数的倍数删掉即可；
    // 埃氏筛法
    for (int i = 2; i <= n; ++ i) {
        if (!st[i]) {
            prime[cnt ++] = i;
            for (int j = i + i; j <= n; j += i) {
                st[j] = 1;
            }
        }
    }
}


int main()
{
    int n = 0;
    cin >> n;
    se_prime(n);
    cout << cnt << endl;
    return 0;
}

