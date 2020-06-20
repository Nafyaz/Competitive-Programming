#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, a[7][7];
    for(i = 1; i < 7; i++)
    {
        for(j = 1; j < 7; j++)
            a[i][j] = 1;
    }

    for(i = 1; i < 7; i++)
        a[i][i] = 0;

    a[1][3] = a[3][1] = 2;
    a[2][4] = a[4][2] = 2;
    a[5][6] = a[6][5] = 2;

    cin >> i >> j;
    cout << a[i][j];
}
