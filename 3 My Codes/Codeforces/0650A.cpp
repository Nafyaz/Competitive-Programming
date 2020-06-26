#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, i, j, ans = 0, u, v;
    scanf("%I64d", &n);

    map <pair <ll, ll>, ll> mp;
    map <ll, ll> mp1, mp2;

    for(i = 0; i < n; i++)
    {
        scanf("%I64d %I64d", &u, &v);
        mp1[u]++;
        mp2[v]++;
        mp[{u, v}]++;
    }

    for(auto it : mp1)
        ans += (it.second)*(it.second-1)/2;

    for(auto it : mp2)
        ans += (it.second)*(it.second-1)/2;

    for(auto it : mp)
        ans -= (it.second)*(it.second-1)/2;


    printf("%I64d", ans);
}
