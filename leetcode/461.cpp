#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int df = 0;
        while (x || y) {
            int a = x&1, b = y&1;
            if (a != b) {
                ++ df;
            }
            x >>= 1;
            y >>= 1;
        }
        return df;
    }
};
