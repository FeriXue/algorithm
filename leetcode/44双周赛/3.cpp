#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& b) {
        int sum = 0;
        int n = b.size() + 1;
        for (int i = 1; i <= n; ++ i) {
            sum ^= i;
        }
        
        for (int i = n - 2; i >= 0; i -= 2) {
            sum ^= b[i]; // sum 此时就是perm1
        }
        
        vector<int> res(1, sum);
        
        for (int i = 0; i < n - 1; ++ i) {
            int t = res.back() ^ b[i];
            res.push_back(t);
        }
        
        return res;
    }
};
