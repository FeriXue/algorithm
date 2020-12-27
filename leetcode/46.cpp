#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> path;
    void dfs(int u, int n, vector<vector<int>> &res, map<int, bool> &st)
    {
        if (u == n) {
            vector<int> tmp;
            for (int i = 0; i < n; ++ i) {
                tmp.push_back(path[i]);
            }
            res.push_back(tmp);
            return;
        }
        for (auto &c : st) {
            if (!c.second) {
                path.push_back(c.first);
                c.second = 1;
                dfs(u + 1, n, res, st);
                c.second = 0;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        map<int, bool> st;
        for (int i = 0; i < nums.size(); ++ i) {
            st[nums[i]] = 0;
        }
        dfs(0, nums.size(), res, st);
        return res;
    }
};
