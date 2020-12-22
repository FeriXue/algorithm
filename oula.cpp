#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int a = 0;
    while (n --) {
        cin >> a;
        int res = a;
        for (int i = 2; i <= a / i; ++ i) {
            if (a % i == 0) { // 说明i是a的一个约数；
                res = res / i * (i - 1); // res = res * (1 - 1 / i); 避免出现小数情况；
                while (a % i == 0) {
                    a /= i;
                }
            }
        }
        if (a > 1) {
            res = res / a * (a - 1);
        }
        cout << res << endl;
    }
    return 0;
}

