//A subtle bug was there. although it won't effect the output.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18

ll t, n, a[300009], b[300009], mn, ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll i, j;
    cin >> t;
    while(t--)
    {
        mn = inf;
        ans = 0;
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
            mn = min({mn, b[i], a[i]});
        }

        for(i = 0; i < n; i++)
        {
            j = (i-1+n)%n;
            if(a[i] > b[j])
                ans = ans + a[i] - b[j];
        }

        cout << ans + mn << endl;

    }
}
