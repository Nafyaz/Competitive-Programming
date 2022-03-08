#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

ll p[2003];
map<ll, ll> mp;
set<ll> special;
vector<pair<ll, ll>> nonSpecial;

void my1st()
{
    ll u, v;
    if(!mp.empty())
    {
        u = (*mp.begin()).ff;
        v = (*mp.begin()).ss;
        if(p[u] >= p[v])
        {
            cout << u << "\n";
            mp.erase(u);
            special.erase(u);
        }
        else
        {
            cout << v << "\n";
            mp.erase(v);
            special.erase(v);
        }
    }
    else
    {
        cout << nonSpecial.back().ss << "\n";
        nonSpecial.pop_back();
    }
}

void his2nd()
{
    ll x;

    cin >> x;

    if(special.find(x) != special.end())
    {
        special.erase(x);
        mp.erase(x);
    }
    else
    {
        auto pos = lower_bound(nonSpecial.begin(), nonSpecial.end(), make_pair(p[x], x));
        nonSpecial.erase(pos);
    }
}

pair<ll, ll> his1st()
{
    ll x, isSpecial;

    cin >> x;

    if(special.find(x) != special.end())
    {
        isSpecial = 1;
    }
    else
    {
        auto pos = lower_bound(nonSpecial.begin(), nonSpecial.end(), make_pair(p[x], x));
        nonSpecial.erase(pos);
        isSpecial = 0;
    }

    return {isSpecial, x};
}

void my2nd(ll hisSpecial)
{

    ll u = hisSpecial;
    ll v = mp[u];

    cout << v << "\n";

    mp.erase(u);
    special.erase(u);

    mp.erase(v);
    special.erase(v);
}

int main()
{
    ll n, m, a, b, t, i;

    cin >> n >> m;

    for(i = 1; i <= 2*n; i++)
        cin >> p[i];

    for(i = 0; i < m; i++)
    {
        cin >> a >> b;

        special.insert(a);
        special.insert(b);

        mp[a] = b;
        mp[b] = a;
    }

    for(i = 1; i <= 2*n; i++)
    {
        if(special.find(i) == special.end())
            nonSpecial.push_back({p[i], i});
    }
    sort(nonSpecial.begin(), nonSpecial.end());

    cin >> t;

    if(t == 1)
    {
        for(i = 1; i <= n; i++)
        {
            my1st();
            his2nd();
        }
    }
    else
    {
        bool heStupid = 0;
        i = 0;
        while(i < 2*n)
        {
            if(!heStupid)
            {
                auto his = his1st();
                i++;

                if(his.ff == 0)
                    heStupid = 1;
                else
                {
                    my2nd(his.ss);
                    i++;
                }
            }
            else
            {
                my1st();
                i++;
                if(i < 2*n)
                {
                    his2nd();
                    i++;
                }
            }
        }
    }
}
