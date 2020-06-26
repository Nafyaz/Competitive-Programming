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
    int t, i;
    string a, b, c, ans;
    cin >> t;
    while(t--)
    {
        ans = "Yes";
        cin >> a >> b >> c;
        for(i = 0; i < a.size(); i++)
        {
            if(c[i] != b[i] && c[i] != a[i])
            {
                ans = "No";
                break;
            }
        }
        cout << ans << endl;
    }
}
