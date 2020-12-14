class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++ i) {
            auto iter = hashtable.find(target - nums[i]);
            if (iter != hashtable.end()) {
                return {iter->second, i};
            } else {
                hashtable[nums[i]] = i;  
            }
        }
        return {};
    }
};

