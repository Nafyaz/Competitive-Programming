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
    int n, m, i;
    cin >> n >> m;

    string s[n], t[m];

    for(i = 0; i < n; i++)
        cin >> s[i];
    for(i = 0; i < m; i++)
        cin >> t[i];

    int q, y;
    cin >> q;

    while(q--)
    {
        cin >> y;
        y--;
        cout << s[y%n] + t[y%m] << endl;
    }
}
