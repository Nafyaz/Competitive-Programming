#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, j, h, a;
    cin >> n >> h;
    ll ans;
    vector<ll> v;
    for(i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
        sort(v.begin(), v.end());
        ll sum = 0;
        for(j = i; j >= 0; j -= 2)
            sum += v[j];
        if(sum <= h)
            ans = i;
    }

    cout << ans+1;
}
