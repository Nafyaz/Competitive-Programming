#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second
#define pb push_back

int main()
{
    ll n, k, i;
    cin >> n >> k;
    ordered_set<ll> s;
    for(i = 1; i * i <= n; i++)
    {
        if(n%i == 0)
        {
            s.insert(i);
            s.insert(n / i);
        }
    }

    if(s.size() < k)
        cout << -1;
    else
        cout << *(s.find_by_order(k-1));
}


