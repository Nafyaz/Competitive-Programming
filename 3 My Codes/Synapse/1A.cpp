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
    int t, caseno = 0, a[200], n, x, i, A, D, pos;
    cin >> t;
    while(t--)
    {
        A = 0;
        cin >> n >> x;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            A ^= a[i];
        }

        sort(a, a+n);
        D = A^x;

        pos = lower_bound(a, a+n, D) - a;

        if(a[pos] != D)
            cout << "Case " << ++caseno << ": " << D << endl;
        else
            cout << "Case " << ++caseno << ": " << -1 << endl;
    }
}
