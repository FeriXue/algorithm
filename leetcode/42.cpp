#include <vector>
#include <stack>

using namespace std;

// 第一种方法
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        int i = 0;
        stk.push(i++);
        while (i < height.size()) {
            while (i < height.size()) {
                if (height[i] >= height[stk.top()]) {
                    break;
                } 
                ++ i;
            }
            if (i < height.size()) {
                int t = stk.top() + 1;
                while (t < i) {
                    res += height[stk.top()] - height[t ++];
                }
                stk.push(i ++);
            }
        }
        int j = height.size() - 1;
        stack<int> st;
        st.push(j --);
        while (j >= stk.top()) {
            while (j >= stk.top()) {
                if (height[j] >= height[st.top()]) {
                    break;
                }
                -- j;
            }
            if (j >= stk.top()) {
                int t = st.top() - 1;
                while (t > j) {
                    res += height[st.top()] - height[t --];
                }
                st.push(j --);
            }
        }
        return res;
    }
};

// 第二种方法
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res = 0, i = 0;
        while (i < height.size()) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int distance = i - st.top() -1;
                int hh = min(height[i], height[st.top()]) - height[top];
                res += distance * hh;
            }
            st.push(i ++);
        }
        return res;
    }
};
