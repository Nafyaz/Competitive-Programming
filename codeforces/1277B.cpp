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
    int t, i, n, a, ans;
    set<int> s;
    cin >> t;
    while(t--)
    {
        s.clear();
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> a;
            if(a%2 == 0)
                s.insert(a);
        }

        ans = 0;
        while(!s.empty())
        {
            a = *(s.rbegin());
            s.erase(a);

            a = a >> 1;
            if(a%2 == 0)
                s.insert(a);
            ans++;
        }
        cout << ans << endl;
    }
}
