#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ld long double
#define ff first
#define ss second


int main()
{
    int t, n, i, a[110], b[110];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];
        for(i = 0; i < n; i++)
            cin >> b[i];

        sort(a, a+n);
        sort(b, b+n);

        for(i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        for(i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << endl;
    }
}
