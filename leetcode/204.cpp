#include <iostream>
#include <cstring>

class Solution {
public:
    int countPrimes(int n) {
        const int N = 5e6 + 10;
        int st[N], prime[N];
        memset(st, 0, sizeof(st));
        int cnt = 0;
        int x = n - 1;

        for (int i = 2; i <= x; ++ i) {
            if (!st[i]) {
                prime[cnt ++] = i;
            }
            for (int j = 0; prime[j] <= x / i; ++ j) {
                st[prime[j] * i] = 1;
                if (i % prime[j] == 0) {
                    break;
                }
            }
        }
        return cnt; 
    }
};
