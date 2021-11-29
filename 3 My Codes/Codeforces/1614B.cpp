#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

pair<ll, ll> p[200005];
ll x[200005];

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.ff > b.ff;
}

int main()
{
    ll T, n, i, val, dist;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
        {
            cin >> p[i].ff;
            p[i].ss = i;
        }

        sort(p+1, p+n+1, cmp);

        x[0] = 0;
        dist = 0;
        for(i = 1, val = 1; i <= n; i++)
        {
            x[p[i].ss] = val;
            dist += 2*abs(x[p[i].ss])*p[i].ff;

            if(val > 0)
                val = -val;
            else
                val = -val + 1;
        }

        cout << dist << "\n";
        for(i = 0; i <= n; i++)
            cout << x[i] << " ";
        cout << "\n";
    }
}
