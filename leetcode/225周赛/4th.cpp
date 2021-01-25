#include <iostream>

class Solution {
public:
    int minimumBoxes(int n) {
        int res = 0;
        int sum = 0, k = 1;
        while (sum + k * (k + 1) / 2 <= n) {
            sum += k * (k + 1) / 2;
            ++k;
        }
        -- k;
        res = k * (k + 1) / 2;
        k = 1;
        while (sum < n) {
            sum += k;
            ++k;
            ++res;
        }
        
        return res;
    }
};
