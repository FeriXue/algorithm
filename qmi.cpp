#include <iostream>

using namespace std;
using LL = long long; 

int qmi(int a, int k, int p)
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
    return 0;
}

