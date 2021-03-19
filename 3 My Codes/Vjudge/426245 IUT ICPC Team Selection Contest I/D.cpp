#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int mat[3009][3009];

int main()
{
    int n, q, i, j, r;
    double cnt;

    while(cin >> n >> q)
    {
        if(!n && !q)
            break;

        pair<int, int> p[n];

        for(i = 0; i < n; i++)
            cin >> p[i].ff >> p[i].ss;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                mat[i][j] = (p[i].ff - p[j].ff)*(p[i].ff - p[j].ff) + (p[i].ss - p[j].ss)*(p[i].ss - p[j].ss);

            sort(mat[i], mat[i] + n);
        }

        while(q--)
        {
            cin >> r;
            r = r*r;

            cnt = 0;
            for(i = 0; i < n; i++)
                cnt += lower_bound(mat[i], mat[i]+n, r+1) - mat[i];

            cout << fixed;
            cout << setprecision(2) << cnt/n << "\n";
        }

        cout << "\n";
    }
}
/*
4 3
1 1
1 2
12 3
40 40
1
10
100
0 0
*/
