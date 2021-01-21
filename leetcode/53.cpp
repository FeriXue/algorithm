#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    const int N = 3e4 + 10;
    int maxSubArray(vector<int>& a) {
        int f[N];
        memset(f, 0, sizeof (f));
        f[0] = a[0];
        for (int i = 1; i < (int)a.size(); ++ i) {
            f[i] = a[i];
            f[i] = max(f[i - 1] + a[i], f[i]);
        }

        int res = -1e5 - 1;
        for (int i = 0; i < (int)a.size(); ++ i) {
            res = max(res, f[i]);
        }
        return res;
    }
};
