#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int heapp[N], heap_size = 0;

void down(int x)
{
    int smallest = x;
    if (2 * x <= heap_size && heapp[2 * x] < heapp[smallest]) {
        smallest = 2 * x;
    }
    if (2 * x + 1 <= heap_size && heapp[2 * x + 1] < heapp[smallest]) {
        smallest = 2 * x + 1;
    }
    if (smallest != x) {
        swap(heapp[smallest], heapp[x]);
        down(smallest);
    }
}

void up(int x)
{
    while (x / 2 && heapp[x / 2] < heapp[x]) {
        swap(heapp[x], heapp[x / 2]);
        x /= 2;
    }
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    heap_size = n;
    for (int i = 1; i <= n; ++ i) {
        scanf("%d", &heapp[i]);
    }

    for (int i = n / 2; i; -- i) {
        down(i);
    }

    while (m --) {
        printf("%d ", heapp[1]);
        heapp[1] = heapp[heap_size--];
        down(1);
    }
    return 0;
}
