#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, d, m, n, i, ans, x[35], total;
    cin >> t;
    while(t--)
    {
        x[1] = 1%m;
        total = x[1];
        cin >> d >> m;
        n = log2(d) + 1;
        for(i = 2; i <= n; i++)
        {
            if(i == n)
                x[i] = (d - total + m)%m;
            else
                x[i] = (x[i-1] << 1)%m;
            total = (total + x[i])%m;
        }
        ans = 0;




        cout << ans << endl;
    }
}
