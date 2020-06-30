#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200009

ll a[N], v1[N], v2[N];
ll rev[N];

void solve()
{
    ll i, n, sum = 0;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(i&1)
            sum += a[i];
    }

    for(i = 1; 2*i <= n; i++)
        v1[i] = a[2*i] - a[2*i - 1];
    for(i = 1; 2*i + 1 <= n; i++)
        v2[i] = a[2*i] - a[2*i + 1];

    ll mx = 0, x = 0;
    for(i = 1; 2*i <= n; i++)
    {
        x += v1[i];
        if(x < 0)
            x = 0;
        mx = max(mx, x);
    }
    x = 0;
    for(i = 1; 2*i + 1<= n; i++)
    {
        x += v2[i];
        if(x < 0)
            x = 0;
        mx = max(mx, x);
    }

    cout << mx + sum << endl;
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
        solve();
}
