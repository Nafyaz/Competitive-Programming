#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i, ans = 0;
    vector<ll> v;

    cin >> n;

    for(i = 1; i*i <= n; i++)
    {
        v.push_back(n/i);
        ans += n/i;
    }

    for(i = n/i; i >= 1; i--)
        ans += i*(v[i-1] - v[i]);

    cout << ans;
}
