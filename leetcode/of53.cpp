class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
            while (l < r) {
                int mid  = (l + r) >> 1;
                if (nums[mid] == mid) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            if (nums[l] == l) {
                return l + 1;
            } else {
                return l;
            }
    }
};
