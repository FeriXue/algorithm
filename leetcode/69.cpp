#include <iostream>

class Solution {
public:
    int search (int x) 
    {
        int l = 0, r = x / 2 + 1;
        while (l < r) {  
            int mid = (l + r + 1) / 2; 
            if (x / mid < mid) {
                r = mid - 1;
            } else {
                l = mid;
            }                  
        }
        return l;
    }

    int mySqrt(int x) {
        return search(x);
    }
};
