#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n, m;

int a[N], b[N];

void insert(int start, int end, int number)
{
    b[start] += number;
    b[end + 1] -= number;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        insert(i, i, a[i]);
    }
    while (m--) {
        int l = 0, r = 0, c = 0;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    for (int i = 1; i <= n; ++i) {
        b[i] += b[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}

