#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ll t, i, j, k, l, b, n;
    string a;
    vector<pair<ll, string>> s;
    cin >> t;
    while(t--)
    {
        s.clear();
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> a >> b;
            s.push_back({b, a});
        }

        sort(s.begin(), s.end());
        map<string, ll> mp;
        for(i = 0; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                b = s[i].ff + s[j].ff;
                for(k = j+1; k < n; k++)
                {
                    if(s[k].ff == b)
                        mp[s[k].ss] = 1;
                    if(s[k].ff > b)
                        break;
                }
            }
        }

        for(i = 0; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                for(k = j+1; k < n; k++)
                {
                    b = s[i].ff + s[j].ff + s[k].ff;
                    for(l = k+1; l < n; l++)
                    {
                        if(s[l].ff == b)
                            mp[s[l].ss] = 1;
                        if(s[l].ff > b)
                            break;
                    }
                }
            }
        }

        cout << mp.size() << endl;
        for(auto u : mp)
            cout << u.ff << endl;
    }
}
