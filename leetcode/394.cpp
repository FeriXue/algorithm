#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

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

class Solutio {
public:

    string decodeString(string s) {
        string ans = "";
        vector<string> stk;

        for (auto &x : s) {
            if (isalnum(x) || x == '[') { // 入栈
                string t = "";
                t.push_back(x);
                stk.push_back(t);
            } else if (x == ']') {
                string temp = "";
                while (stk.back() != "[") {
                    temp += stk.back();
                    stk.pop_back();
                }
                stk.pop_back();
                int times = 0;
                int bit = 1;
                string tm = stk.back();
                while (isdigit(tm[0])) {
                    times += stoi(tm) * bit;
                    bit *= 10;
                    stk.pop_back();
                    tm = stk.back();
                    //cout << stk.back() << "@@@@@@@" << endl;
                 }
                --times;
                stk.pop_back();
                reverse(temp.begin(), temp.end());
                string cp = temp;
                while (times--) {
                    temp += cp;
                }
                cout << temp << endl;
                /*for (auto &c : temp){
                    string er(1, c);
                    //stk.push_back(er);
                }*/
            }
        }

        if (stk.empty()) {
            cout << 1 << endl;
        } else {
            cout << "mother fc" << endl;
            cout << stk.back() << endl;
        }

        return ans;
    }
};
