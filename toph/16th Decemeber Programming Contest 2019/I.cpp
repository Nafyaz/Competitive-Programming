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
#define PI 2*acos(0)

int main()
{
    int t;
    long double a, r, ans, p;
    cin >> t;
    while(t--)
    {
        cin >> a;
        r = sqrt(a)/2;
        ans = a - PI*r*r;
        p = 2*PI*r;

        cout << fixed;
        cout << setprecision(9) << ans << " " << setprecision(9) << p << endl;
    }
}
