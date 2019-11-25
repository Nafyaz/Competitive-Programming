#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, mn = 110;
    cin >> n;
    int a[n], p[n];

    for(i = 0; i < n; i++)
    {
        cin >> a[i] >> p[i];

        if(mn > p[i])
        {
            mn = p[i];
        }

        p[i] = mn;
    }

    int ans = 0;

    for(i = 0; i < n; i++)
        ans += a[i]*p[i];

    cout << ans;
}
