#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return 0;
        }
        deque<int> que;
        unsigned long mod = 10, div = 1, t = 0;
        while (x) {
            t = x % mod;
            t = t / div;
            x = x - t * div;
            que.push_back(t);
            mod *= 10;
            div *= 10;
        } 
        while (!que.empty()) {
            if (que.front() == que.back() && que.size() != 1) {
                que.pop_front();
                que.pop_back();
            } else if (que.size() == 1) {
                return 1;
            } else {
                return 0;
            }
        }
        return 1;
    }
};
