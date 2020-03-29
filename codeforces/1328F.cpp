#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ll n, k, a, i;
    cin >> n >> k;

    map<ll, ll> freq;
    for(i = 0; i < n; i++)
    {
        cin >> a;
        freq[a]++;
        if(freq[a] >= k)
        {
            cout << 0;
            return 0;
        }
    }

    n = freq.size();
    vector<pair<ll, ll> > v(n+2), left(n+2), right(n+2);

    i = 1;
    for(auto u : freq)
    {
        v[i].ff = u.ff;
        v[i].ss = u.ss;
        i++;
    }

    for(i = 1; i <= n; i++)
    {
        left[i].ff = left[i-1].ff + v[i].ss;
        left[i].ss = left[i-1].ss + v[i].ss*v[i].ff;
//        cout << i << " " << left[i].ff << " " << left[i].ss << endl;
    }
    for(i = n; i >= 1; i--)
    {
        right[i].ff = right[i+1].ff + v[i].ss;
        right[i].ss = right[i+1].ss + v[i].ss*v[i].ff;
    }

/*
    for(i = 0; i <= n+1; i++)
        cout << setw(4) << v[i].ff << setw(3) << v[i].ss;
    cout << endl;
    for(i = 0; i <= n+1; i++)
        cout << setw(4) << left[i].ff << setw(3) << left[i].ss;
    cout << endl;
    for(i = 0; i <= n+1; i++)
        cout << setw(4) << right[i].ff << setw(3) << right[i].ss;
    cout << endl;
*/

    ll x, y, req, ans = LLONG_MAX;
    for(i = 1; i <= n; i++)
    {
        req = k - v[i].ss;
        x = max(0LL, (v[i].ff - 1)*left[i-1].ff - left[i-1].ss);
        y = max(0LL, right[i+1].ss - (v[i].ff + 1)*right[i+1].ff);

        if(left[i-1].ff >= req)
            ans = min(ans, x + req);
        if(right[i+1].ff >= req)
            ans = min(ans, y + req);
        ans = min(ans, x+y + req);

//        cout << i << " " << x << " " << y << " " << req << endl;
    }

    cout << ans;
}
