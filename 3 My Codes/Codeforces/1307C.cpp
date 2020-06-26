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
    ll i, n;
    string s;
    cin >> s;
    n = s.size();
    vector<pair<ll, char>> a(n);
    map<char, ll> freq;

    for(i = 0; i < n; i++)
    {
        freq[s[i]]++;
//        a[i].ff = freq[s[i]];
//        a[i].ss = s[i];
    }

//    sort(a.begin(), a.end());

//    for(auto u : a)
//        cout << u.ss << " " << u.ff << endl;

    if(n == 1)
        cout << 1;
    else
    {
        ll mx = 0, x, rem;
        char p, q;

        for(p = 'a'; p <= 'z'; p++)
        {
            for(q = 'a'; q <= 'z'; q++)
            {
                x = rem = 0;
                for(i = 0; i < n; i++)
                {
                    if(s[i] == q)
                        rem++;
                    else if(s[i] == p)
                        x += freq[q] - rem;
                }

                mx = max(mx, x);
            }
        }

        for(auto u : freq)
        {
            mx = max(mx, u.ss*(u.ss-1)/2);
            mx = max(mx, u.ss);
        }

        cout << mx;
    }
}
