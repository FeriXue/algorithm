#include <iostream>

using namespace std;

int main()
{
    char s[20];
    int i = 6, j = 9;
    sprintf(s, "%03d : %04d", i, j);
    cout << s << endl;
    return 0;
}

