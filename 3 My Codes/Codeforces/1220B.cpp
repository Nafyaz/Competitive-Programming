#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, i, j, gcd = 0;
    cin >> n;
    long long a[n][n], ans[n];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    ans[0] = sqrt(a[0][1]*a[0][2]/a[1][2]);

    for(i = 1; i < n; i++)
        ans[i] = a[0][i]/ans[0];

    for(i = 0; i < n; i++)
        cout << ans[i] << " ";
}
