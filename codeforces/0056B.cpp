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
    cin >> n;
    int a[n+1], b[n+1], flag = 0;
    for(i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    for(i = 1; i <= n; i++)
    {
        if(a[i] != i)
        {
            reverse(a+i, a+a[i]+1);
            flag = 1;
            break;
        }
    }

    if(flag && is_sorted(a+1, a+n+1))
        cout << i << " " << b[i];
    else
        cout << "0 0";
}
