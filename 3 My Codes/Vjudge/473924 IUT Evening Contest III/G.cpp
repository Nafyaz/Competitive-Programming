#include<bits/stdc++.h>
using namespace std;

int a[1003][1003];
int r[1003], c[1003];

int main()
{
    int n, i, j;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cin >> a[i][j];
    }

    for(i = 0; i < n; i++)
        cin >> r[i];
    for(i = 0; i < n; i++)
        cin >> c[i];


}
