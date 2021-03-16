#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 暴力解法
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& s) {
        vector<int> ans;
        int n = s.size();
        for (int i = 0; i < n; ++ i) {
            bool flag = 0;
            for (int j = i + 1; j < n; ++ j) {
                if (s[j] > s[i]) {
                    flag = 1;
                    ans.push_back(j - i);
                    break;
                }
            }
            if (!flag) {
                ans.push_back(0);
            }
        }
        return ans;
    }
};

// 单调栈
class Solution2 {
public:
    vector<int> dailyTemperatures(vector<int>& s) {
        int n = s.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        for (int i = 0; i < n; ++ i) {
            while (!stk.empty()) {
                int t = stk.top();
                if (s[t] < s[i]) {
                    stk.pop();
                    ans[t] = i - t;
                } else {
                    break;
                }
            }
            if (stk.empty() || s[stk.top()] >= s[i]) {
                stk.push(i);
            }
        }

        while (!stk.empty()) {
            int t = stk.top();
            stk.pop();
            ans[t] = 0;
        }

        return ans;
    }
};
