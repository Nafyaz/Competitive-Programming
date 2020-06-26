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

int main()
{
    ll n;
    cin >> n;
    ll a, i, j, pos[n+1];

    for(i = 1; i <= n; i++)
    {
        cin >> a;
        pos[a] = i;
    }

    ll avg, sum = 0, x, ans[n+1];
    for(i = 1; i <= n; i++)
    {
        sum += pos[i];
        avg = sum/i;

        x = 0;
        for(j = 1; j <= i; j++)
            x += abs(avg - pos[j]);

        ans[i] = x;
        x = 0;
        for(j = 1; j <= i; j++)
            x += abs(avg+1 - pos[j]);

        ans[i] = min(ans[i], x);
    }

    for(i = 1; i <= n; i++)
        cout << ans[i] << " ";
}

