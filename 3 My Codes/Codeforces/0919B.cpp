//Shitty Bruteforce approace
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

int add(int n)
{
    int s = 0;
    while(n)
    {
        s += n%10;
        n /= 10;
    }
    return s;
}

int main()
{
    int i, cnt = 0, n, k;
    cin >> k;

    for(i = 19; cnt < k; i++)
    {
        if(add(i) == 10)
            cnt++;
    }

    cout << i-1;
}
