#include <iostream>

using namespace std;

int n, x;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    cin >> n;
    while (n--) {
        cin >> x;
        int number = 0;
        while (x) {
            x -= lowbit(x);
            number ++;
        }
        cout << number << " ";
    }
    cout << lowbit(10) << endl;
    return 0;
}

