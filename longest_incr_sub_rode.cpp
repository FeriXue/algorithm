#include <iostream>

using namespace std;

const int N = 1010;

int a[N];
int f[N], g[N];

int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; ++ i) {
        f[i] = 1;
        g[i] = 0;
        for (int j = 0; j < i; ++ j) {
            if (a[j] < a[i]) {
                if (f[j] + 1 > f[i]) {
                    f[i] = f[j] + 1;
                    g[i] = j;
                }
            }
        }
    }

    int k = 0;
    for (int i = 0; i < n; ++ i) {
        if (f[i] > f[k]) {
            k = i;
        }
    }

    cout << f[k] << endl;

    for (int i = 0, len = f[k]; i < len; ++ i) {
        cout << a[k] << " ";
        k = g[k];
    }

    return 0;
}

