#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int numPrimeArrangements(int n) {
        const int mod  = 1e9 + 7;
        const int N = 1e5 + 10;
        vector<int> prime;
        int cnt = 0;
        bool st[N];
        memset(st, 0, sizeof(st));
        for (int i = 2; i <= n; ++ i) {
            if (!st[i]) {
                prime.push_back(i);
                ++ cnt;
            }
            for (int j = 0; prime[j] <= n / i; ++ j) {
                st[prime[j] * i] = 1;
                if (i % prime[j] == 0) {
                    break;
                }
            }
        }
        long long res = 1, prime_num = cnt, com_num = n - cnt;
        while (prime_num) {
            res =  res * prime_num % mod;
            -- prime_num;   
        }   
        while (com_num) {
            res = res * com_num % mod;
            -- com_num;
        }
        return res;
    }
};
