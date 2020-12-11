#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 35;
int son[N][2];                    
int cnt[N], now_in;

void insert(int x)
{
    for (int i = 0; i < N; ++ i) {
        for (int j = 0; j < 2; ++ j) {
            son[i][j] = -1;
        }
    }

    vector<int> x_bina;
    while (x / 2 != 0) {
        x_bina.push_back(x % 2);
        x /= 2;
    }
    x_bina.push_back(x % 2);
    // reverse(x_bina.begin(), x_bina.end());

    for (auto &c : x_bina) {
        cout << c;
    }
    cout << endl;


    int father = 0;
    for (decltype(x_bina.size()) i = 0; i < x_bina.size(); ++ i) {
        if (son[father][x_bina[i]] == -1) {
            son[father][x_bina[i]] = ++ now_in;
        }
        father = son[father][x_bina[i]];
    }
    ++ cnt[father];
}

int get_max_num()
{
    int father = 0;
    vector<int> maxx;
    while (cnt[father] == 0)
    {
        if (son[father][0] == 1 && son[father][1] == 0) {
            maxx.push_back(1);
        } else {
            maxx.push_back(0);
        }
        ++ father;
    }
    int max_num = 0;
    for (decltype(maxx.size()) i = 0; i < maxx.size(); ++ i) {
        for (int j = maxx.size() - 1; j <= 0; -- j) {
            max_num = max_num + i * 2;
        }
    }
    return max_num;
}

int main()
{
    int n = 0;
    int x = 0;
    cin >> n;
    while (n -- ) {
        cin >> x;
        insert(x);
    }

    //cout << get_max_num() << endl;
    return 0;
}

