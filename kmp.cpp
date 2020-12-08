#include <iostream>                                                                        

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10; 
char s[M], p[N];
int ne[N];

int main()
{
    int n = 0, m = 0;
    cin >> n >> p >> m >> s;
    // 求next数组
    ne[0] = -1;
    for (int i = 1, j = -1; i < n; ++ i) {
        while (j != -1 && p[j + 1] != p[i]) {
            j = ne[j];
        }
        if (p[j + 1] == p[i]) {
            ++ j;
        }
        ne[i] = j;
    }   

    //KMP匹配过程
    for (int i = 0, j = -1; i < m; ++i) {
        while (j != -1 && p[j + 1] != s[i]) {
            j = ne[j];
        }
        if (p[j + 1] == s[i]) {
            ++ j;
        }
        if (j == n - 1) {
            printf("%d ", i - n + 1); 
            j = ne[j];
        }
    }   
    return 0;
}

