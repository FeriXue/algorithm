#include <iostream>

using namespace std;

// 欧几里得算法求最大公约数
int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a % b) : a;
}

int main()
{
    int n = 0;
    cin >> n;
    int a = 0, b = 0;

    while (n --) {
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }

    return 0;
}

