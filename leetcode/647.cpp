#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        const int N = 1010;
        vector<vector<int>> dp(N, vector<int> (N));
        for (int i = 1; i < N; ++ i) {
            dp[i][i] = 1;
        }
        
        string str(1, ' ');
        str += s;
        int n = s.size();
        int sum = n;

        for (int j = 2; j <= n; ++ j) {
            for (int i = 1; i < j; ++ i) {
                if (str[i] == str[j] && j == i + 1) {
                    dp[i][j] = 1;
                    sum ++;
                } else if (str[i] == str[j] && dp[i + 1][j - 1]) {
                    sum ++;
                    dp[i][j] = 1;
                }
            }
        }
           
        return sum;
    }
};
