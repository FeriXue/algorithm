#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 10;

int heapp[N], heap_size = 0;
int ph[N], hp[N];

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(heapp[a], heapp[b]);
}

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
        heap_swap(smallest, x);
        down(smallest);
    }
}

void up(int x)
{
    while (x / 2 && heapp[x / 2] > heapp[x]) {
        heap_swap(x, x / 2);
        x /= 2;
    }
}

int main()
{
    int n = 0, now_in = 0;
    string op;
    cin >> n;
    while (n --) {
        cin >> op;
        if (op == "I") {
            int x = 0;
            cin >> x;
            ++ heap_size;
            ++ now_in;
            ph[now_in] = heap_size;
            hp[heap_size] = now_in;
            heapp[heap_size] = x;
            up(heap_size);
        } else if (op == "PM") {
            printf("%d\n", heapp[1]);
        } else if (op == "DM") {
            heap_swap(1, heap_size);
            -- heap_size;
            down(1);
        } else if (op == "D") {
            int k = 0;
            cin >> k;
            int heap_pos = ph[k]; // 得到第k个插入的数在堆中的位置;
            heap_swap(ph[k], heap_size);
            -- heap_size;
            down(heap_pos); // 如果这里的参数写成了ph[k]那么其实down的是最后一个已经不存在的堆中的位置因为在之前元素对调的时候相应的ph数组中第k个插入元素的位置已经被改变了
            up(heap_pos);
        } else if (op == "C") {
            int x = 0, k = 0;
            cin >> k >> x;
            heapp[ph[k]] = x;
            down (ph[k]);
            up(ph[k]);
        }
    }
    return 0;
}
