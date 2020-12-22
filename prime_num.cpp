#include <iostream>

using namespace std;

bool prime_num(int n)
{
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= n / i; ++ i) { //i * i <= n;
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n = 0, x = 0;
    cin >> n;
    while (n --) {
        cin >> x;
        if (prime_num(x)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

