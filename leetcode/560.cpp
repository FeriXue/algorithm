#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sum{nums[0]};

        for (int i = 1; i < nums.size(); ++ i) {
            sum.push_back(sum[i - 1] + nums[i]);
        }
        int value = 0, res = 0;
        for (int begin = 0; begin < nums.size(); ++ begin) {
            for (int end = begin; end < nums.size(); ++ end) {
                if (begin - 1 == -1) {
                    value = sum[end];
                } else {
                    value = sum[end] - sum[begin - 1];
                }
                if (value == k) {
                    ++ res;
                }
            }
        }
        return res;
    }
};

class Solution {
  public:
      int subarraySum(vector<int>& nums, int k) {
          int res = 0;
          map<int, int> mp;
          mp[0] = 1;
          int sum = 0;
          for (auto &c : nums) {
              sum += c;
              if (mp.find(sum - k) != mp.end()) {
                  res += mp[sum - k];
              }
              mp[sum] += 1;
          }
          return res;
      }
  };


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};


