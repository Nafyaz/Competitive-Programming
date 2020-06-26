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
    int t, n;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n&1)
        {
            s = '7';
            n -= 3;
            s = s + string(n>>1, '1');
        }
        else
        {
            s = string (n>>1, '1');
        }

        cout << s << endl;
    }
}
