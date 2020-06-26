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
    int t, n, i, a[200009], ans;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < 2*n; i++)
        {
            cin >> a[i];
        }
        sort(a, a+2*n);
        cout << abs(a[n] - a[n-1]) << endl;
    }
}
