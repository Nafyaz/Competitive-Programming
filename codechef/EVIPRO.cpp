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
    ll t, i, j, ans, stsum, sum;
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
            if(i != s.size() - 1)
            {
                st[i] = ss[i] ^ ss[i+1];
                sum += !st[i];
                if(!st[i])
                    st[i] = -1;
                stsum += st[i];
            }
            else
                st[i] = 0;

            if(i != 0)
            {
                ed[i] = ss[i] ^ ss[i-1];
                if(!ed[i])
                    ed[i] = -1;
            }
            else
                ed[i] = 0;
        }

//        cout << sum << endl;

        for(i = 0; i < s.size(); i++)
        {
            ans += sum*(s.size() - i) + stsum + ed[i]*(s.size() - i);
            stsum -= st[i];
        }

        cout << ans << endl;
    }
}
