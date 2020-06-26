#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

#define N 250009

ll fact[N];

int main()
{
    ll i, n, m;

    cin >> n >> m;

    fact[0] = fact[1] = 1;

    for(i = 2; i < N; i++)
        fact[i] = (fact[i-1]*i)%m;

    ll ans = (fact[n]*n)%m, x;
    for(i = 1; i < n; i++)
    {
        x = (fact[i] * fact[n-i+1])%m;
        x = x*i;
        ans = (ans + x)%m;
    }

    cout << ans;


}
