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
    ll n, m;
    cin >> n >> m;
    ll i, j, a[n], b[n], x;

    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    sort(a, a+n);
    sort(b, b+n);

    int flag;
    for(i = 0; i < n; i++)
    {
        flag = 1;
        x = (b[i] - a[0] + m)%m;
        for(j = 0; j < n; j++)
        {
            if(x != (b[(j+i)%n] - a[j] + m)%m)
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            cout << x;
            break;
        }
    }
}
