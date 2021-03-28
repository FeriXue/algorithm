#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    void push_in(vector<string> &stk, char c)
    {
        string t(1, c);
        stk.push_back(t);
    }

    string pop_in(vector<string> &stk)
    {
        string res = "";
        while(stk.back() != "[") {
            res += stk.back();
            stk.pop_back();
        }
        stk.pop_back(); // 将'['出栈；
        return res;
    }

    int get_times(vector<string> &stk)
    {
        int ans = 0, fund = 1;
        string t = stk.back();
        while (isdigit(t[0])) {
            ans += stoi(t) * fund;
            fund *= 10;
            stk.pop_back();
            t = stk.back();
        }
        return ans;
    }

    string decodeString(string s) {
        string ans = "";
        vector<string> stk;
        for (auto &x : s) {
            if (isalnum(x) || x == '[') {
                // 执行入栈操作；
                push_in(stk, x);
            } else {
                string res = pop_in(stk);// 执行出栈操作；
                reverse(res.begin(), res.end());// 翻转
                int times = get_times(stk);// 获得重复次数times
                string mod = res;
                while (--times) { // 重复
                    res += mod;
                }
                for (auto &c : res) { // 重新入栈
                    push_in(stk, c);
                }
            }
        }

        for (auto &x : stk) {// 最终栈中就是解码后的字符串
            ans += x;
        }

        return ans;
    }
};
