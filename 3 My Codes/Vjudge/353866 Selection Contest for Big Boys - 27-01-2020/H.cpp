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

ll binexpo(ll n, ll k)
{
    if(k == 0)
        return 1;
    ll ans = binexpo(n, k>>1), res = 1;
    if(k&1)
        res = n;
    return ans*ans*res;
}

int main()
{
    ll k;
    cin >> k;
    cout << binexpo(2, k+1)-1;
}
