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

map<int, int> mp;

void func(int n)
{
    while(n)
    {
        mp[n%10]++;
        n /= 10;
    }
}

int main()
{
    freopen("out1.txt", "w", stdout);
    int n;
    for(n = 1; n <= 10000; n++)
    {
        mp.clear();
        int i, mx = -1, mxcnt = -1;
    //    cin >> n;
        for(i = 1; i <= n; i++)
        {
            func(i);
        }

        for(auto u : mp)
        {
            if(mxcnt <= u.ss)
            {
                mxcnt = u.ss;
                mx = u.ff;
            }
        }

        cout << n << " " << mx << endl;
    }

}
