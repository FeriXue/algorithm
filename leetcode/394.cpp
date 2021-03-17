#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reverse(string s) {
        string ans;
        for (int i = s.size() - 1; i != -1; -- i) {
            ans += s[i];
        }
        return ans;
    }

    string stk_pop(stack<char> &stk) {
        string ans;
        while (stk.top() != '[') {
            ans += stk.top();
            stk.pop();
        }
        stk.pop();
        return ans;
    }

    void push_stack(stack<char> &stk, string t) {
        for (auto &c : t) {
            stk.push(c);
        }
    }

    string decodeString(string s) {
        string ans;
        stack<char> stk;
        for (auto &c : s) {
            if (c != ']') {
                stk.push(c);
            } else {
                string t = stk_pop(stk);
                t = reverse(t);
                int time = stk.top();
                stk.pop();
                while (time --) {
                    t += t;
                }
                push_stack(stk, t);
            }
        }
        
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        ans = reverse(ans);

        return ans;
    }
};
