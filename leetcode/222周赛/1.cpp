#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

// way 1;
class Solution {
public:
    const int N = 1e3 + 10;
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int cnt[N];
        memset(cnt, 0, sizeof(cnt));
        for (auto i = boxTypes.begin(); i != boxTypes.end(); ++ i) {
            auto t = *i;
            cnt[*(-- t.end())] += * (t.begin());
        }
        int res = truckSize;
        int ou = 0;
        for (int i = N - 1; i >= 0; -- i) {
            if (!res) {
                break;
            }
            if (cnt[i] != 0) {
                if (cnt[i] >= res) {
                    ou += i * res;
                    res = 0;
                } else if (cnt[i] < res) {
                    ou += i * cnt[i];
                    res -= cnt[i];
                }
            }
        }
        return ou;
    }
};

// way 2
class Solutio {
public:
    const int N = 1e3 + 10;
    int maximumUnits(vector<vector<int>>& b, int m) {
        sort(b.begin(), b.end(), [](vector<int> a, vector<int> b) ->int {return a[1] > b[1];});
        int res = 0;
        for (int i = 0; i < b.size(); ++ i) {
            int cur = min(m,b[i][0]);
            res += cur * b[i][1];
            m -= cur;
        }
        return res;
    }
};
