#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, t = 0;
        int n = gain.size();
        for (int i = 0; i < n; ++ i) {
            t += gain[i];
            res = max(res, t);
        }
        return res;
    }
};
