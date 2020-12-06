#include <iostream>
#include <vector>

using namespace std;

vector<int> cut(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;

    for (decltype(A.size()) i = 0; i < A.size(); ++i) {
        t = A[i] - t;
        if (i < B.size()) {
            t -= B[i];
        }
        C.push_back((t + 10) % 10);
        if (t < 0) {
            t = 1;
        } else {
            t = 0;
        }
    }
    
    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();
    }

    return C;
}

bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size()) {
        return A.size() > B.size(); // 如果a大于b返回true，否则返回false;
    } else {
        for (int i = A.size() - 1; i >= 0; --i) {
            if (A[i] != B[i]) {
                return A[i] > B[i];
            }
        }
        return true;
    }
}

void print_final(vector<int> &c)
{
    for (int i = c.size() - 1; i >= 0; --i) {
        printf("%d", c[i]);
    }
}

int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B;

    for (int i = a.size() - 1; i >= 0; --i) {
        A.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; --i) {
        B.push_back(b[i] - '0');
    }

    if (cmp(A, B)) {
        auto C = cut(A, B);
        print_final(C);
    } else {
        auto C = cut(B, A);
        printf("-");
        print_final(C);
    }

    printf("\n");

    return 0;
}

