#include <iostream>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ou;
        vector<string> copy_str = strs;
        map<string, vector<string>> hash_map;
        
        for (int i = 0; i < copy_str.size(); ++ i) {
            sort(copy_str[i].begin(), copy_str[i].end());
        }
        for (int i = 0; i < strs.size(); ++ i) {
            hash_map[copy_str[i]].push_back(strs[i]);
        }
        for (auto i = hash_map.begin(); i != hash_map.end(); ++ i) {
            ou.push_back(i->second);
        }
        
        return ou;
    }
};
