#include <iostream>                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
#include <unistd.h>

using namespace std;

const int N = 1e5 + 10; 

int l[N], r[N], value[N];
int now_in;

void init()
{
    r[0] = 1;
    l[0] = -1; 
    l[1] = 0;
    r[1] = -1; 
    now_in = 2;
}

//在下标为k的点的右边插入x；
void insert(int k, int x)
{
    value[now_in] = x;
    r[now_in] = r[k];
    l[now_in] = k;
    l[r[k]] = now_in;
    r[k] = now_in++;
}

void zleft_insert(int x)
{
    insert(0, x); 
}

void zright_insert(int x)
{
    insert(l[1], x); 
}

// 删除第k个点；
void delete_one(int k)  
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    init();
    int m = 0;
    cin >> m;
    string op; 
    int k = 0, x = 0;
    while (m--) {
        cin >> op; 
        if (op == "L") {
            cin >> x;
            zleft_insert(x);
        } else if (op == "R") {
            cin >> x;
            zright_insert(x);
        } else if (op == "D") {
            cin >> k;
            delete_one(k + 1); 
        } else if (op == "IL") {
            cin >> k >> x;
            insert(l[(k + 1)], x);
        } else if (op == "IR"){
            cin >> k >> x;
            insert(k + 1, x); 
        }   
    }   

    for (int i = r[0]; i != 1; i = r[i]) {
        cout << value[i] << " ";
    } 
    cout << endl;
    
    return 0;
}

