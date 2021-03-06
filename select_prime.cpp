#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int prime[N], st[N], cnt;

void se_prime(int n)
{
    // 朴素筛法，时间复杂度为O(nlogn);
    for (int i = 2; i <= n; ++ i) {
        if (!st[i]) {
            prime[cnt ++] = i;
        }
        for (int j = i + i; j <= n; j += i) {
            st[j] = 1;
        }
    }
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
    // 线性筛法
    // 合数只会被它的最小质因子筛掉；
    for (int i = 2; i <= n; ++ i) {
        if (!st[i]) { //如果i是一个质数那么就将i加入到质数集合中;
            prime[cnt ++] = i;
        }
        // 两种情况，i是合数 && i是质数
        for (int j = 0; prime[j] <= n / i; ++ j) { // 当质数大于n/i的时候就break掉   
            // 每一次把当前的质数和i的乘积筛掉
            // 只用最小质因子来筛掉某一个数;
            // 对于一个合数x，假设pj是x的最小质因子，当i枚举到x/pj的时候就一定会把x筛掉
            st[prime[j] * i] = 1; // 合数pj * i只会被它的最小质因子筛掉；            
            // 当这句话成立时，意味着pj一定是i最小质因子；
            if (i % prime[j] == 0) { // 意味着prime数组已经走到了最后一个元素        
                // 当pj是i的最小质因子的时，++ i；                                   
                // i % pj == 0  pj一定是i的最小质因子，pj一定是pj * i的最小质因子；  
                // i % pj != 0  pj一定小于i的所有质因子,pj也一定是pj * i的最小质因子 
                break;                                                               
            }                                                                        
        }                                                                            
    }
    // 线性筛法重写
    
    for (int i = 2; i <= n; ++ i) {
        if (!st[i]) {
            prime[cnt ++] = i;
        }
        for (int j = 0; prime[j] <= n / i; ++ j) {
            st[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                break;
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

