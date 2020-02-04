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
    ll n, a, b, k, i, ans = 0;
    cin >> n >> a >> b >> k;
    ll h, x;

    multiset<ll> ms;
    for(i = 0; i < n; i++)
    {
        cin >> h;
        x = h%(a+b);
        if(x == 0)
            ms.insert(a+b);
        else if(x > a)
            ms.insert(x);
        else
            ans++;
    }

//    cout << ans << endl;

//    while(!ms.empty())
//    {
//        cout << *ms.begin() << " ";
//        ms.erase(ms.begin());
//    }

    ll reqhit;
    while(!ms.empty() && k)
    {
        x = *ms.begin();
        reqhit = (x+a-1)/a;
        if(k >= max(1LL, reqhit-1))
        {
            k -= max(1LL, reqhit-1);
            ans++;
            ms.erase(ms.begin());
        }
        else
            break;
    }

    cout << ans;
}
