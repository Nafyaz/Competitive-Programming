#include<bits/stdc++.h>
using namespace std;

int a[4][4009], b[2][16000009];

int main()
{
    int t, n, i, j, ans;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < 4; j++)
                cin >> a[j][i];
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                b[0][i*n+j] = a[0][i] + a[1][j];
                b[1][i*n+j] = a[2][i] + a[3][j];
            }
        }


        sort(b[1], b[1]+n*n);

        ans = 0;
        for(i = 0; i < n*n; i++)
            ans += upper_bound(b[1], b[1]+n*n, -b[0][i]) - lower_bound(b[1], b[1]+n*n, -b[0][i]);

        cout << ans << "\n";

        if(t)
            cout << "\n";
    }
}
