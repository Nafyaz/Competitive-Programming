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
    int n, i;
    ll sum = 0;
    cin >> n;
    int m[n], s[n];
    for(i = 0; i < n; i++)
    {
        cin >> m[i] >> s[i];
        sum += m[i];
    }
    if(n == 0)
    {
        cout << 0;
        return 0;
    }
    int ans = 0, avg = (sum + n-1)/n;
    for(i = 0; i < n; i++)
    {
        if(m[i] >= 150 && m[i] >= avg && 10LL*m[i] >= 7LL*s[i])
            ans++;
    }
    cout << ans;
}
