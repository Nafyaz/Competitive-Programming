#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll c[31];
    ll n, L, i, j;

    cin >> n >> L;

    for(i = 0; i < n; i++)
        cin >> c[i];

    for(i = 1; i < n; i++)
        c[i] = min(c[i-1], c[i]);

    for(i = n; i < 31; i++)
        c[i] = c[i-1] * 2;

    for(i = 0; l > 0; i++)
    {

    }


    ll ans = 0;
    for(i = 0; i < n; i++)
        ans += c[i]*bottleCnt[i];

    cout << ans;
}
