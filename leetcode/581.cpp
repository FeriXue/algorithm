#include <vector>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }
        auto st1 = nums.begin() + 1, st2 = nums.begin();
        auto ed1 = nums.end() - 2, ed2 = nums.end() - 1;
        while (st1 != nums.end() && *st1 >= *st2) {
            if (*st1 > *st2) {
                ++st1, ++st2;
            } else if (*st1 == *st2) {
                ++st1;
            }
        }
        while (ed1 != nums.begin() - 1 && *ed1 <= *ed2) {
            if (*ed1 < *ed2) {
                --ed1, --ed2;
            } else if (*ed1 == *ed2) {
                --ed1;
            }
            
        }
        int sum = 0;
        if (st1 != nums.end()) {
            sum = 1;
            while (st2 != ed2) {
                ++ st2;
                ++ sum;
            }
        }
        return sum;
    }
};
