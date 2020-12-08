#include <iostream>

using namespace std;

const int N = 1e6 + 10;                                                                                                                                       

int a[N],q[N];

int main()
{
    int n = 0, k = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
    }
    // 之所以在队列中存放下标而不是值，是因为在这里通过下标隐式的维护了一个长度为k的窗口，
    // 我们需要通过下标来判断队列中的值是否还在窗口中
    //
    //
    //判断滑动窗口中的最小值
    int hh = 0, tt = -1;
    for (int i = 0; i < n; ++ i) {
        if (hh <= tt && i - k + 1 > q[hh]) {
            ++ hh;
        }
        // 在队列中没有元素的时候，不需要判断队头是否在队列中，也不需要判断即将进入队列的元素和队中元素的大小关系
        while (hh <= tt && a[q[tt]] >= a[i]) {
            -- tt;
        } // 保证了队列中的值都是小于a[i]的
        q[++ tt] = i; // 将当前元素的下标存入队列中，在这之前我们必须保证队列中的值都是小于a[i]的
        if (i >= k - 1) {
            printf("%d ", a[q[hh]]);
        }
    }
    cout << endl;
    //
    //判断滑动窗口中的最大值

    hh = 0,  tt = -1;
    for (int i = 0; i < n; ++ i) {
        // 判断队头是否还在窗口中
        if (hh <= tt && i - k + 1 > q[hh]) {
            ++ hh;
        }
        while (hh <= tt && a[q[tt]] <= a[i]) {
            -- tt;
        }
        q[++ tt] = i;
        if (i >= k - 1) {
            printf("%d ", a[q[hh]]);
        }
    }

    return 0;
}

