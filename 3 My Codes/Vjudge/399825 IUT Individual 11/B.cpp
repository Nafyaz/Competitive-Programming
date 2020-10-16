#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second
#define pb push_back

int is_prime(int n)
{
    if(n == 1)
        return 0;

    for(int i = 2; i * i <= n; i++)
    {
        if(n%i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int i = 1, sum = 0;
    for(i = 1; i <= 100; i ++)
    {
//        sum += (__builtin_popcount(i) == 2? 1 : 0);
//        cout << i << " " << sum << "\n";
        if(__builtin_popcount(i) == 2)
            cout << i << "\n";
    }
}

