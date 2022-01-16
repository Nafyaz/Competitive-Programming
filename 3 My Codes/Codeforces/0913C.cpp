#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, L, i;
    ll c[32];

    cin >> n >> L;

    for(i = 0; i < n; i++)
        cin >> c[i];

    for(i = 1; i < n; i++)
        c[i] = min(2*c[i-1], c[i]);

    ll ans = LLONG_MAX, sum = 0;
    for(i = n-1; i >= 0; i--)
    {
        ll need = L / (1LL << i);
        sum += need * c[i];
        L -= need * (1LL << i);
        ans = min(ans, sum + (L>0)*c[i]);
    }

    cout << ans;
}
