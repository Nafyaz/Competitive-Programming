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

ll ss[3000009], st[3000009], ed[3000009];

int main()
{
    ll t, i, j, k, ans, stsum, sum;
    string s;
    cin >> t;

    while(t--)
    {
        ans = stsum = sum = 0;
        cin >> s;
        for(i = 0; i < s.size(); i++)
            ss[i] = s[i] - '0';
        for(i = 0; i < s.size(); i++)
        {
            for(j = i; j < s.size(); j++)
            {
                for(k = 0; k < s.size(); k++)
                {
                    if(k <= j && k >= i)
                        st[k] = !ss[k];
                    else
                        st[k] = ss[k];
//                    cout << st[k];

                    if(k > 0 && st[k] == st[k-1])
                        ans++;
                }
//                cout << endl;
            }
        }

        cout << ans << endl;
    }
}
