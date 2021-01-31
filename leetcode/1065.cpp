#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    void insert(string &s, vector<vector<int>> &son, vector<int> &cnt, int &now_in)
    {
        int p = 0;
        for (auto &c : s) {
            int u = c - 'a';
            if (!son[p][u]) {
                son[p][u] = ++now_in;
            }
            p = son[p][u];
        }
        ++ cnt[p];
    }

    vector<vector<int>> query(string s, vector<vector<int>> &son, vector<int> &cnt)
    {
        vector<vector<int>> res;

        for (int i = 0; i < s.size(); ++i) {
            int u = s[i] - 'a', p = 0;
            int k = i;
            cout << i << endl;
            while (son[p][u]) {
                p = son[p][u]; 
                if (cnt[p]) {
                    res.push_back({i, k});
                }
                if (k + 1 == s.size()) {
                    break;
                }
                ++ k;
                u = s[k] - 'a';
            }
        }
        return res;
    }

    vector<vector<int>> indexPairs(string s, vector<string>& l) {
        const int N = 1010;
        int now_in = 0;
        vector<vector<int>> son(N, vector<int>(26, 0));
        vector<int> cnt(N, 0);
        for (int i = 0; i < l.size(); ++ i) {
            insert(l[i], son, cnt, now_in);
        }
        vector<vector<int>> ans = query(s, son, cnt);
        return ans;
    }
};
