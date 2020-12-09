class Solution {
public:
    int findString(vector<string>& words, string s) {
        int l = 0, r = words.size() - 1;
        int mid = 0, test_mid = 0;
        while (l < r) {
            mid = (l + r + 1) >> 1;
            test_mid = mid;
            while (words[test_mid] == "" && test_mid <= r) {
                ++ test_mid;
            }
            if (test_mid > r) {
                r = mid - 1;
            } else if (test_mid <= r){
                mid = test_mid;
                if (words[mid] > s) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
        }
        if (words[l] == s) {
            return l;
        } else  {
            return -1;
        }
    }
};
