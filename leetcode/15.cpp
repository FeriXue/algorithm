#include <iostream>                                                                                                                                                                                                               
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ou;
        int n = nums.size();
        for(int i = 0; i < n; ++ i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int k = n - 1, second = -1, third = -1;
            for (int j = i + 1; j < n; ++ j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                while (j < k && nums[i] + nums[j] + nums[k] > 0) {
                    -- k;
                }
                second = j;
                if (second == k && nums[i] + nums[j] + nums[k - 1] >= 0) {
                    third = k - 1;
                    break;
                }
                if (j == k && nums[i] + nums[j] + nums[k - 1] < 0) {
                    break;
                }
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ou.push_back({nums[i], nums[j], nums[k]});
                }
            }
            if (second != -1 && third != -1 && second == third && nums[i] + nums[second] + nums[k] > 0) {
                break;
            }
        }
        return ou;
    }
};

