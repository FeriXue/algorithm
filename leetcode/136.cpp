#include <iostream>
#include <vector>

using namespace std;

/*给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 任何数和0异或仍然等于本身
        // 任何数和本身异或得到0
        // 异或运算满足交换律和结合律a^b^a=b^a^a=b^(a^a)=b^0=b
        int ans = 0;
        for (auto &c : nums) {
            ans ^= c;
        }
        return ans;
    }
};
