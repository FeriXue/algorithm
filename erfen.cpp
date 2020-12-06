#include <iostream>

bool check(int);

// 区间[l, r]区间被划分成[l, mid - 1], 和 [mid, r]时
int bsearch_1(int l, int r)
{
    while (l < r) {
        int mid = (l + r +1) >> 1;// 上取整；
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return 0;
}

// 区间[l, r]区间被划分成[l, mid], 和 [mid + 1, r]时

int bsearch_2(int l, int r)       
{                                 
    while (l < r) {               
        int mid = (l + r) >> 1;
        if (check(mid)) {         
            r = mid;              
        } else {                  
            l = mid + 1;          
        }                         
    }                             
    return 0;                     
}                                 
