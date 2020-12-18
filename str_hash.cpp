#include <iostream>

using namespace std;

using ULL = unsigned long long;// 溢出相当于取模

const int N = 1e5 + 10, pp = 131;

char strr[N];
ULL h[N], p[N];// 此处的p数组用来存储p的次方

ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    int n = 0, m = 0;
    scanf("%d%d%s", &n, &m, strr + 1);
    
    p[0] = 1;
    for (int i = 1; i <= n; ++ i) {
        p[i] = p[i - 1] * pp;
        h[i] = h[i - 1] * pp + strr[i];
    }

    while (m --) {
        int l1 = 0, r1 = 0, l2 = 0, r2 = 0;
        cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

