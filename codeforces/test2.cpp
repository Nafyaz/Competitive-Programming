#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ld long double
#define ll long long
#define ff first
#define ss second

ld f(ld x)
{
    return 3*x*x + 2*x + 5;
}

int main()
{
    long double x, h, i;
    cout << fixed;
    for(i = -10; i <= 10; i += .1)
    {
        cout << setprecision(1) << i << ": " << setprecision(3) << setw(5) << f(i) << "; ";
    }

    cout << endl << endl;

    h = 0.0000001;
//    for(i = -10; i <= 10; i += .1)
//    {
//        cout <<
//    }
}
