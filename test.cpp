#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    map<int, vector<int>> hash_map;
    hash_map[1].push_back(3);
    cout << hash_map[1][0] << endl;
    return 0;
}

