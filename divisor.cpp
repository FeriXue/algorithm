#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 试除法求一个数的所有约数

vector<int> get_divisor(int n)
{
    vector<int> res;
    for (int i = 1; i <= n / i; ++ i) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) {        
                res.push_back(n / i);
            }                        
        }
    }
    sort(res.begin(), res.end());
    return res;
}


int main()
{
    int n = 0;
    cin >> n;
    int a = 0;
    while (n --) {
        cin >> a;
        vector<int> divisor = get_divisor(a);
        for (auto &c : divisor) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}

