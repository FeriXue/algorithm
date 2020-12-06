#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n = 0;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r) {
        return; // 判断边界，如果区间里面只有一个数或者没有数就直接返回
    }

    int x = q[l], i = l - 1, j = r + 1; // 取分节点x， 两个指针
    while (i < j) {
        do {
            i++;
        } while (q[i] < x); // 当q[i]的值大于等于x的时候则停止指针移动
        do {
            j--;
        } while(q[j] > x); // 当q[j]的值小于等于x的时候停止移动
        if (i < j) {
            swap(q[i], q[j]); // 交换值，条件是 i < j;
        }
    }

    quick_sort(q, l, j); // quick_sort(q, l, i - 1);
    quick_sort(q, j + 1, r); // quick_sort(q, i, r) 如果这里的边界值为i，那么上面确定的分界点x的值就一定不能写 x = q[l]
    // 否则会存在边界问题(死循环)， 如果写i的，x = q[r]或者 x = q[(l + r + 1) / 2](上取整，保证取不到l此边界)

}


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) { // 向数组中键入数字
        scanf("%d", &q[i]);
    }

    quick_sort(q, 0, n-1); // 执行快速排序

    for (int i = 0; i < n; ++i) { // 将排序结果输出
        printf("%d ", q[i]);
    }
    return 0;
}

