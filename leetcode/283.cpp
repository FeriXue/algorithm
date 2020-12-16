#include <iostream>
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;
        while (r < n) {
            if (nums[l] != 0 && nums[r] != 0) {
                ++l, ++r;
            } else if (nums[l] == 0 && nums[r] != 0) {
                swap(nums[l], nums[r]);
                ++ l, ++ r;
            } else if (nums[l] == 0 && nums[r] == 0) {
                ++ r;
            }
        } 
    }
};

// 不同的写法
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;
        while (r < n) {
            if (nums[r]) {
                swap(nums[l], nums[r]);
                ++ l;// 保证了当执行交换的时候l <= r;
            }
            ++ r;
        }
    }
};
