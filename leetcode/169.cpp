#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> hash;
        int cnt = 0, ans = 0;
        for (auto &x : nums) {
            ++hash[x];
            // 使用打擂台的方式维护最大值，免去了对哈希表的遍历
            if (hash[x] > cnt) {
                ans = x;
                cnt = hash[x];
            }
        }
        return ans;
    }
};
