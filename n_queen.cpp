#include <iostream>
#include <vector>

using namespace std;

const int N = 10;

int n;
vector<vector<char>> queen;
bool col[N], dg[N], udg[N];

void dfs(int u)
{
    if (u == n) {
        for (int i = 0; i < n ; ++ i) {     
            for (int j = 0; j < n; ++ j) {  
                cout << queen[i][j] << " ";
            }                               
            cout << endl;
        }                                   
        cout << endl;
        return;
    }

    for (int i = 0; i < n; ++ i) {
        if (!col[i] && !dg[u + i] && !udg[u - i + n - 1]) {
            queen[u][i] = 'Q';
            col[i] = dg[u + i] = udg[u - i + n - 1] = 1;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[u - i + n - 1] = 0;
            queen[u][i] = '.';
        }
    }
}

int main()
{
    cin >> n;
    vector<char> nq;

    for (int i = 0; i < n ; ++ i) {
        for (int j = 0; j < n; ++ j) {
            nq.push_back('.');  
        }
        queen.push_back(nq);
    }

    dfs(0);
    return 0;
}

