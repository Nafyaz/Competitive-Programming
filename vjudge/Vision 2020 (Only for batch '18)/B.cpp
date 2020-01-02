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

bool is_prime(int n)
{
    int x = sqrt(n)+1;

    for(int i = 2; i < x; i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;

    if(n <= 3)
    {
        cout << -1;
        return 0;
    }

    n -= 2;

    if(is_prime(n))
        cout << 2 << " " << n;
    else
        cout << -1;
}
