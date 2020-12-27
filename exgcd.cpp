#include <iostream>

using namespace std;

// 扩展欧几里得算法

int exgcd(int a, int b, int &x, int &y)
{
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main()
{
    int n = 0;
    int a = 0, b = 0, x = 0, y = 0;
    while (n --) {
        cin >> a >> b;
        exgcd(a, b, x, y);
        cout << x << " " << y << endl;                                                                                         
    }
    return 0;
}
