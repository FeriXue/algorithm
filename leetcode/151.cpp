#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        auto green = s.end() - 1, red = s.end();
        string res;
        while (green >= s.begin()) {
            if (*(green) != ' ') { // 排除空格
                res += ' '; // ~~~~~~~~~~~~是否加空格取决于能否找到下一个非空格字符
                red = green;// 让red指向单词的最后一个字母;
                while (green >= s.begin() && *green != ' ') { // 寻找单词的首字母
                    -- green;
                }
                auto t = green + 1;// 此时的green要么是首前位置，要么是单词的前一个位置
                while (t <= red) {
                    res += *t;
                    ++ t;
                }
            }
            -- green;
        }
        string ans(res, 1);
        return ans;
    }
};
