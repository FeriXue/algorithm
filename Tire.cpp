#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 10;

int son[N][26], cnt[N], now_in;

void insert_tire(string s)
{
    int father = 0; // 此处的father的值代表的含义是第几个字母接下来的字母是什么
    for (decltype(s.size()) i = 0; i < s.size(); ++ i) {
        int u = s[i] - 'a';
        if (!son[father][u]) {
            son[father][u] = ++ now_in; // 此处的++now_in代表的是一个字符串中的第几个字母，真正的字符串中的字母是由下标存储的
            // 此处son[father][u]中存储的值的含义是这是第几层;
        }
        father = son[father][u];
    }

    ++ cnt[father];
}

void insert_second(string s)
{
    int father = 0;
    for (decltype(s.size()) i = 0; i < s.size(); ++ i) {
        int u = s[i] - 'a';
        if (!son[father][u]) {
            son[father][u] = ++ now_in;
        }
        father = son[father][u];
    }
    ++ cnt[father];
}

int query_seco(string s)
{
    int father = 0;
    for (decltype(s.size()) i = 0; i < s.size(); ++ i) {
        int u = s[i] - 'a';
        if (!son[father][u]) {
            return 0;
        } else {
            father = son[father][u];
        }
    }
    return cnt[father];
}

int query(string s) 
{
    int father = 0;
    for (decltype(s.size()) i = 0; i < s.size(); ++ i) {
        int u = s[i] - 'a';
        if (!son[father][u]) {
            return 0;
        } else {
            father = son[father][u];
        }
    }
    return cnt[father];
}

int main()
{
    int n = 0;
    cin >> n;
    string a, b;
    while (n --) {
        cin >> a >> b;
        if (a == "I") {
            insert_tire(b);
        } else if (a == "Q") {
            cout << query(b) << endl;
        }
    }
    return 0;
}

