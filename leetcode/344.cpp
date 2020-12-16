#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int r = s.size() - 1;
        for (int l = 0; l < s.size(); ++ l) {
            if (l < r) {
                swap(s[l], s[r --]);
            }
        } 
    }
};
