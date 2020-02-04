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
    int n, k, i, j;
    cin >> n >> k;
    int a[n];

    for(i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n, greater<int>());

    cout << a[k-1] << endl;
}
