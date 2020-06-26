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
    int a, b, n, flag = 0;
    cin >> a >> b >> n;

    for(int i = 0; i < 10; i++)
    {
        if((10*a+i)%b == 0)
        {
            cout << a << i;
            flag = 1;
            n--;
            break;
        }
    }

    if(flag)
    {
        while(n--)
            cout << 0;
    }
    else
        cout << -1;
}
