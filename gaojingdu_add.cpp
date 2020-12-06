#include <iostream>
#include <vector>

using namespace std;

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
        C.push_back(t % 10);
        t = t / 10;
    }
    if (t) {
        C.push_back(1);
    }

    return C;
}

int main()
{
    string str_a, str_b;
    cin >> str_a >> str_b;

    vector<int> A, B;
    for (int i = str_a.size() - 1; i >= 0; --i) {
        A.push_back(str_a[i] - '0');
    }
    for (int i = str_b.size() - 1; i >=0; --i) {
        B.push_back(str_b[i] - '0');
    }

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; --i) {
        printf("%d", C[i]);
    }
    printf("\n");

    return 0;
}

