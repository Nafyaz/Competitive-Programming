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

int ans[100009];

int main()
{
    int q, qno = 0, n, i, val;
    cin >> q;
    while(q--)
    {
        cin >> n;
        if(ans[n] != 0)
        {
            cout << "Query " << ++qno << ": " << ans[n] << endl;
            continue;
        }
        val = sqrt(n);
        for(i = 2; i <= val + 1; i++)
        {
            if(n%i != 0 && n%i == n%(i*i) && n >= i*i)
                ans[n]++;
        }

        cout << "Query " << ++qno << ": " << ans[n] << endl;
    }
}
