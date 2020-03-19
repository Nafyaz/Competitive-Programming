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
    int t, n, k, i, j, ans[109][109];
    cin >> t;
    while(t--)
    {
        cin >> n;
        if((n*(n-1)/2) % n != 0)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        for(i = 0; i < n; i++)
        {
            ans[i][i] = 0;
            k = (n-1)/2;
            for(j = (i+1)%n; j != i; j = (j+1)%n)
            {
                if(k)
                {
                    ans[i][j] = 1;
                    k--;
                }
                else
                    ans[i][j] = 0;
            }
        }

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
                cout << ans[i][j];
            cout << endl;
        }
    }
}
