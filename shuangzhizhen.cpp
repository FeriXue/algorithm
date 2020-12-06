#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int a[N], tag[N];

int main()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    int max_length = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        tag[a[i]]++;
        while (tag[a[i]] > 1) {
            tag[a[j]]--;
            j++;
        }
        max_length = max(max_length, i - j + 1);
    }
    cout << max_length << endl;
    return 0;
}

