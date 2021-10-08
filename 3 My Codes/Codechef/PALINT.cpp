#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll t, n, x, i, a, b, eq, op;

    cin >> t;

    while(t--)
    {
        map<ll, set<ll>> mp;
        map<ll, ll> freqa, freqb;

        cin >> n >> x;

        for(i = 0; i < n; i++)
        {
            cin >> a;
            b = a ^ x;

            freqa[a]++;
            freqb[b]++;

            mp[a].insert(i);
            mp[b].insert(i);
        }

        eq = 0, op = 0;
        for(auto u : mp)
        {
            if(u.ss.size() > eq)
            {
                eq = u.ss.size();
                if(x == 0)
                    op = 0;
                else
                    op = freqb[u.ff];
            }
            else if(u.ss.size() == eq)
            {
                if(x == 0)
                    op = 0;
                else
                    op = min(op, freqb[u.ff]);
            }
        }

        cout << eq << " " << op << "\n";
    }
}
