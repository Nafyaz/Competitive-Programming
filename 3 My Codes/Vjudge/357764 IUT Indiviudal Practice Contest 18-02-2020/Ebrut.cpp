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
    int n = 3;
    int i, j, ans, cnt, a[n];
    iota(a, a+n, 1);
    for(i = 0; i <= n*n/2; i++)
    {
        cnt = 0;
        while(next_permutation(a, a+n))
        {
            ans = 0;
            for(j = 0; j < n; j++)
                ans += abs(j+1 - a[j]);
            cnt += (ans == i);
        }

        cout << i << " " << cnt << endl;
    }
}
