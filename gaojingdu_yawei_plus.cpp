#include <iostream>                                                                                                                                                                                                                                                             
#include <vector>

using namespace std;

const int base = 1e9;

vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (decltype(A.size()) i = 0; i < A.size() || i < B.size(); ++i) {
        if (i < A.size()) {
            t += A[i];
        }
        if (i < B.size()) {
            t += B[i];
        }
        C.push_back(t % base);
        t = t / base;
    }
    if (t) {
        C.push_back(t);
    }

    return C;
}

int main()
{
    string str_a, str_b;
    cin >> str_a >> str_b;

    vector<int> A, B;
    for (int i = str_a.size() - 1, s = 0, t = 1, j = 0; i >= 0; --i) {
        s += (str_a[i] - '0') * t;
        t *= 10;
        ++j;
        if (j == 9 || i == 0) {
            A.push_back(s);
            s = 0;
            j = 0;
            t = 1;
        }

    }
    for (int i = str_b.size() - 1, s = 0, t = 1, j = 0; i >=0; --i) {
        s += (str_b[i] - '0') * t;
        t *= 10;
        ++j;
        if (j == 9 || i == 0) {
            B.push_back(s);
            s = 0;
            j = 0;
            t = 1;
        }
    }

    auto C = add(A, B);

    cout << C.back(); // 第一个数不需要最高位补0
    for (int i = C.size() - 2; i >= 0; --i) {
        printf("%09d", C[i]); // 剩余数据需要最高位补0；
    }
    printf("\n");

    return 0;
}

