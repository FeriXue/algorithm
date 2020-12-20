#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> ou;
        map<int, int> ou_B;
        for (int i = 0; i < B.size(); ++ i) {
            ou_B[B[i]] = i;
        }
        
        for (int i = 0; i < A.size(); ++ i) {
            ou.push_back(ou_B[A[i]]);
        }
        return ou;
    }
};
