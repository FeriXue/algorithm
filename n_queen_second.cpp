#include <iostream>
#include <vector>

using namespace std;

const int N = 10; 

int n;
vector<vector<char>> queen;
bool row[N], col[N], dg[N], udg[N];

void dfs(int x, int y, int s) {
    if (y == n) {
        ++ x;
        y = 0;
    }
    if (x == n) {
        if (s == n) {
            for (int i = 0; i < n ; ++ i) {             
                for (int j = 0; j < n; ++ j) {  
                    cout << queen[i][j] << " ";
                }                               
                cout <<endl;
            }                                   
            cout << endl;
        }
        return;
    }

    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n - 1]) {
        queen[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n - 1] = 1;
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n - 1] = 0;
        queen[x][y] = '.';
    }

        dfs(x, y + 1, s);
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

    dfs(0, 0, 0);
    return 0;
}

