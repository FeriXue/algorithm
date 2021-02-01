#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void insert(vector<vector<int>> &son, vector<int> &cnt, int &now_in, string s)
    {
        int p = 0;
        for (int i = 0; i < (int)s.size(); ++ i) {
            int u = s[i] - 'a';
            if (!son[p][u]) {
                son[p][u] = ++now_in;
            }
            p = son[p][u];
        }
        ++cnt[p];
    }

    void qurey(vector<vector<int>> &son, vector<int> &cnt, int p, string &res, string &ans)
    {

        for (int u = 0; u < 26; ++ u) {
            if (son[p][u] && cnt[son[p][u]]) {
                res += u + 'a';
                qurey(son, cnt, son[p][u], res, ans);
                if (res.size() > ans.size()) {
                    ans = res;
                } else if (res.size() == ans.size()) {
                    ans = min(ans, res);
                }
                res.pop_back();
            }
        }
    }

    string longestWord(vector<string>& s) {
        const int N = 30010;
        int now_in = 0;
        vector<vector<int>> son(N, vector<int>(26));
        vector<int> cnt(N);

        for (auto &c : s) {
            insert(son, cnt, now_in, c);
        }

        string ans, res;
        qurey(son, cnt, 0, res, ans);
        return ans;
    }
};
