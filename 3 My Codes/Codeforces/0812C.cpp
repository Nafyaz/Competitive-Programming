#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, a[100005];

ll cost(ll k)
{
    ll i, ret = 0;
    vector<ll> v;
    for(i = 1; i <= n; i++)
        v.push_back(a[i] + k*i);

    sort(v.begin(), v.end());

    for(i = 0; i < k; i++)
        ret += v[i];

    return ret;
}

int main()
{
    ll S, i, l, r, mid, midCost, ans, ansCost;

    cin >> n >> S;

    for(i = 1; i <= n; i++)
        cin >> a[i];

    l = 0, r = n;
    while(l <= r)
    {
        mid = (l+r)/2;
        midCost = cost(mid);

        if(midCost <= S)
        {
            l = mid + 1;
            ans = mid;
            ansCost = midCost;
        }
        else
            r = mid - 1;
    }

    cout << ans << " " << ansCost;
}

