#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& d) {
        int res = 0, mod = 1e9 + 7;
        unordered_map<int, int> hash;
        for (auto c : d) {
            for (int i = 0; i <= 21; ++ i) {
                int t = (1 << i) - c;
                if (hash.count(t)) {
                    res = (res + hash[t]) % mod;
                }
            }
            ++ hash[c];
        }
        return res;
    }
};
