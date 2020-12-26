#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int head = 0, tail = students.size() - 1;
        int can = 0, i = 0;
        while (head <= tail) {
            if (students[i] == sandwiches[can]) {
                ++ can, ++ head, ++ i;
            } else {
                int j = 0;
                for (j = head+1; j <= tail; ++ j) {
                    if (students[j] == sandwiches[can]) {                               
                        break;
                    }   
                }   
                if (j > tail) {
                    break;
                }   
                while (i < j) {
                    students.push_back(students[i]);
                    ++ head, ++ tail, ++ i;
                }   
            }   
        } 
        return sandwiches.size() - can;
    }
};
