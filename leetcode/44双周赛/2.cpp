#include <iostream>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

// 答案正确，但是超时了;
// 总结：
// 1 ： 将已经能正常交流的人剔除思路正确
// 2 ： 没有进一步的分析题意，没有将剩下的人使用同一种语言更清楚的提炼出来，而是枚举了使用每种语言交流要教会的最少人数
// 3 ： 实际上只需要求出会同一种语言最多的人数，给剩下的人教会此种语言即可；
class Solution {
public:
    
    int h[510], val[510], ne[510], w[510], now_in = 0;
    
    void add(int a, int b, int c) {
        val[now_in] = b;
        w[now_in] = c;
        ne[now_in] = h[a];
        h[a] = now_in ++;
    }
    
    void cant(vector<vector<int>>& lan, vector<vector<int>>& fri)
    {
        for (int i = 0; i < (int)fri.size(); ++ i) {
            int usera = fri[i][0] - 1, userb = fri[i][1] - 1;
            int flag = 0;
            for (int i = 0; i < (int)lan[usera].size(); ++ i) {
                for (int j = 0; j < (int)lan[userb].size(); ++ j) {
                    if (lan[usera][i] == lan[userb][j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag) {
                    break;
                }
            }
            
            if (!flag) {
                add(usera + 1, userb + 1, 0);
            }
        }
        
    }
    
    int minimumTeachings(vector<vector<int>>& lan, vector<vector<int>>& fri) { 
        memset(h, 0xff, sizeof(h));
        cant(lan, fri);
        int ans = 1e9;
    
        for (int i = 1; i != 505; ++ i) {
            int res = 0;
            for (int k = 1; k != 505; ++ k) {
                if(h[k] != -1) {
                    int user = k - 1, flag = 0;
                    for (int m = 0; m < (int)lan[user].size(); ++ m) {
                        if(lan[user][m] == i) {
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag) {
                        lan[user].push_back(i);
                        res += 1; 
                    }
                    
                    for (int j = h[k]; j != -1; j = ne[j]) {
                        int uj = val[j] - 1, flag = 0;
                        for (int x = 0; x < (int)lan[uj].size(); ++ x) {
                            if (lan[uj][x] == i) {
                                flag = 1;
                                break;
                            }
                        }
                        if (!flag) {
                            lan[uj].push_back(i);
                            res += 1;
                        }
                    }
                }
            }
            ans = min(ans, res);
        }
        return ans;
    }
};


class Solutio {
public:
    int minimumTeachings(int n, vector<vector<int>>& lg, vector<vector<int>>& fs) {

        int m = lg.size();
        vector<vector<bool>> g(m + 1, vector<bool>(n + 1));

        for (int i = 0; i < m; ++ i) {
            for (auto &c : lg[i]) {
                g[i + 1][c] = true;
            }
        }

        set<int> cant;

        for (int i = 0; i < (int)fs.size(); ++ i) {
            int x = fs[i][0], y = fs[i][1];
            int flag = false;
            for (int i = 1; i <= n; ++ i) {
                if (g[x][i] && g[y][i]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }
            cant.insert(x);
            cant.insert(y);
        }

        vector<int> cnt(n + 1);
        int s = 0;
        for (auto &c : cant) {
            for (int i = 1; i <= n; ++ i) {
                if (g[c][i]) {
                    ++ cnt[i];
                    s = max(s, cnt[i]);
                }
            }
        }

        return cant.size() - s;
    }
};
