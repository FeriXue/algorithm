#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


// way 1
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int, int> hash;
        for (int i = 0; i < (int)nums.size(); ++ i) {
            hash[i] = 0;
        }
        for (int i = 0; i < (int)nums.size(); ++ i) {
            auto t = hash.find(nums[i]);
            t->second = 1;
        }
        auto iter = hash.begin();
        while (iter->second == 1) {
            ++ iter;
        }
        return iter->first;
    }
};

// way 2

class Solutio {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size(); ++ i) {
            if (i != nums[i]) {
                return i;
            }
        }
        return nums.size();
    }
};
