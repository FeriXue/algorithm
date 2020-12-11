#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int father[N];

int find(int x) // 返回x的祖宗节点，并且使用递归实现路径压缩；
{
    if (father[x] != x) { // 说明此节点还不是祖宗节点
        father[x] = find(father[x]);// 递归实现1循环找到x的祖宗节点，2利用返回值实现路径压缩;
    }
    return father[x];
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++ i) {
        father[i] = i; // 初始化每一个集合的父节点，此时每个集合中只有一个元素所以father[i] == i；
    }
    string s;
    int a = 0, b = 0;
    while (m --) {
        cin >> s >> a >> b;
        if (s == "M") {
            father[find(a)] = find(b);
        } else if (s == "Q") {
            if (find(a) == find(b)) {
                cout << "Yes";
            } else {
                cout << "No";
            }
        }
    }
    return 0;
}

