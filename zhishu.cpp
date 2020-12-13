#include <iostream>

using namespace std;

int main()
{
    for (int i = 100000; ; ++ i) {
        bool y = 1;
        for (int j = 2; j * j <= i; ++ j) {
            if (i % j == 0) {
                y = 0;
                cout << i << "not " << endl;
                break;
            }
        }
        if (y) {
            cout << i << "yes" << endl;
            break;
        }
    }
    return 0;
}

