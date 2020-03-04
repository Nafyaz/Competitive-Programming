#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ld long double
#define ll long long
#define ld long double
#define ff first
#define ss second

<<<<<<< HEAD
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
=======
int main()
{
    bitset<5> b;
    while(b)
    {
        cout << "lol";
    }
>>>>>>> 0d8fb2884b68b487a141121e6b6a15ab5e611aeb
}
