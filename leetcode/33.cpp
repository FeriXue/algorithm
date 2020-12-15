#include <vector>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int back = 0;
        int l = 0, r = nums.size() - 1;
        int last = r;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > nums[last]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int revolve = l;
        if (target <= nums[last]) {
            int ll = revolve, rr = nums.size() - 1;
            while (ll < rr) {
                int mid = (ll + rr) >> 1;
                if (target > nums[mid]) {
                    ll = mid + 1;
                } else {
                    rr = mid;
                }
                              
            }
            if (nums[ll] == target) {
                back = ll;
            } else {
                    back = -1;
            }
        } else {
            int le = 0, re = revolve - 1;
            while (le < re) {
                int mid = (le + re) >> 1;
                if (target > nums[mid]) {
                    le = mid + 1;
                } else {
                    re = mid;
                } 
            }
            if (nums[le] == target) {
                back = le;
            } else {
                back = -1;
            }
        }
        return back;
    }
} ;


