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

        int mi = *st2, ma = *st2;
        auto iter = st2;
        auto ll = st2, rr = ed2;
        while (iter <= ed2) {
            if (*iter < mi) {
                mi = *iter;
            } else if (*iter > ma) {
                ma = *iter;
            }
            ++iter;
        }
        int sum = 0;
        if (st1 != nums.end()) {
            sum = 1;
            while (st2 != ed2) {
                ++ st2;
                ++ sum;
            }
        }

        if (ll != nums.begin() && st1 != nums.end() && ll < rr) {

            auto left = ll - 1;
            while (left >= nums.begin() && mi < *left) {
                --left;
                ++sum;
            }
        }

        if (rr != nums.end() - 1 && ll < rr) {
            auto right = rr + 1;
            while (right != nums.end() && ma > *right) {
                ++right;
                ++sum;
            }
        }


        return sum;
    }
};
