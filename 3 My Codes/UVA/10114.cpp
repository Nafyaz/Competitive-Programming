#include<bits/stdc++.h>
using namespace std;
int main()
{
    int dm, n, i, m;
    double dp, l, dr[109];

    while(cin >> dm >> dp >> l >> n)
    {
        if(dm < 0)
            break;

        memset(dr, 0, sizeof dr);

        for(i = 0; i < n; i++)
        {
            cin >> m >> dr;
            dr[m] = dr;
        }

        for(i = 0; i < dm; i++)
        {
            if(dr[i] == 0 && i)
                dr[i] = dr[i-1];


        }

    }
}
