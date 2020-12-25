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
    ll n, i, m, b1, b2, diff, pos;
    ll price[10009];
    while(cin >> n)
    {
        for(i = 0; i < n; i++)
            cin >> price[i];
        sort(price, price+n);
        cin >> m;

        diff = INT_MAX;
        for(i = 0; i < n && price[i] <= m/2; i++)
        {
            pos = lower_bound(price + i + 1, price+n, m-price[i]) - price;
            if(pos < n && price[pos] == m-price[i] && diff > price[pos] - price[i])
            {
                b1 = price[i];
                b2 = price[pos];
                diff = price[pos] - price[i];
            }
        }

        cout << "Peter should buy books whose prices are " << b1 << " and " << b2 << "." << endl << endl;
    }
}
