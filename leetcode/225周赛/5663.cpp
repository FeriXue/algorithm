#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& w, int k) {
        vector<int> q;
        int m = w.size(), n = w[0].size();
        for (int i = 0; i < m; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (i) {
                    w[i][j] ^= w[i - 1][j];
                }
                if (j) {
                    w[i][j] ^= w[i][j - 1];
                }
                if (i && j) {
                    w[i][j] ^= w[i - 1][j - 1];
                }
                q.push_back(w[i][j]);
            }
        }
        sort(q.begin(), q.end());
        auto t = q.end() - k;
        return *t;
    }
};
