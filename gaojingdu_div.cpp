#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> div(vector<int> A, int b, int &r)
{
    vector<int> C;

    for (int i = A.size() - 1; i >= 0; --i) {
        r = r * 10 + A[i]; // 借位乘10，从个位开始除
        C.push_back(r / b); // 假如不够除就是商0 
        r = r % b; // 余数
    }
    reverse(C.begin(), C.end());

    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }
    return C;
}

int main()
{
    // 给定两个整数a, b 计算a / b 的商和余数；
    string a;
    int b = 0;
    cin >> a >> b;
    vector<int> A;
    
    for (int i = a.size() - 1; i >= 0; --i) {
        A.push_back(a[i] - '0');
    }

    int r = 0; // 表示余数
    auto C = div(A, b, r);

    for (int i = C.size() - 1; i >= 0; --i) {
        printf("%d", C[i]);
    }
    printf("\n");
    printf("%d\n", r);

    return 0;
}

