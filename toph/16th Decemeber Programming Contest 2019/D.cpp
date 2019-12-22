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
    int n;
    long double a, b, e, x1, y1, x2, y2, l, ae;

    cin >> n;
    while(n--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> l;
        if(l == 0)
        {
            cout << 0 << endl;
            continue;
        }
        a = l/2;
        ae = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))/2;
        e = ae/a;
        b = a*sqrt(1 - e*e);

        cout << fixed;
        cout << setprecision(9) << PI*a*b << endl;
    }
}
