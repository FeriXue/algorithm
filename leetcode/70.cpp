#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(1);
        f.push_back(1), f.push_back(2);
        for (int i = 3; i <= n; ++ i) {
            f.push_back(f[i - 1] + f[i - 2]);
        }
        return f[n];
    }
};
