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

int x, y, z;

bool func(int n)
{
    int i, val = sqrt(n);
    for(i = 2; i <= val; i++)
    {
        if(i != z && n%i == 0)
        {
            x = i;
            y = n/i;
            if(x != z && y != z && x != y)
                return 0;
        }
    }
    return 1;
}
int main()
{
    int t, n, val, flag, i;
    cin >> t;
    while(t--)
    {
        flag = 0;
        cin >> n;
        val = sqrt(n);
        for(i = 2; i <= val; i++)
        {
            z = i;
            if(n%i == 0 && func(n/i) == 0)
            {
                flag = 1;
                cout << "YES" << endl << x << " " << y << " " << z << endl;
                break;
            }
        }

        if(!flag)
            cout << "NO" << endl;
    }
}
