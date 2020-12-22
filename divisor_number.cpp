#include <iostream>
#include <unordered_map>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
    unordered_map<int, int> hashh;
    int n = 0;
    cin >> n;
    int x = 0;
    while (n --) {
        cin >> x;
        for (int i = 2; i <= x / i; ++ i) {
            while (x % i == 0) {
                x /= i;
                ++ hashh[i];
            }
        }
        if (x > 1) {
            ++ hashh[x];
        }
    }

    long long res = 1;
    for (auto &c : hashh) {
        res = res * (c.second + 1) % mod;
    }

    cout << res << endl;
    return 0;
}

