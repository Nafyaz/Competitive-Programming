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
    int t, n, d, a, b;
    cin >> t;
    while(t--)
    {
        cin >> n >> d;

        a = sqrt(d);
        if(a + (d+a)/(a+1) <= n)
        {
            cout << "YES" << endl;
            continue;
        }
        a--;
        if(a + (d+a)/(a+1) <= n)
        {
            cout << "YES" << endl;
            continue;
        }
        a += 2;
        if(a + (d+a)/(a+1) <= n)
        {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }
}
