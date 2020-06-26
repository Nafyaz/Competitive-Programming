#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, i;
    cin >> n;
    ll b;
    set <ll> st[65];

    for(i = 0; i < n; i++)
    {
        cin >> b;
        st[__builtin_ctzll(b)].insert(b);
    }

    ll mxsize = -1, mxidx = -1;
    for(i = 0; i < 65; i++)
    {
        if(mxsize < st[i].size())
        {
            mxsize = st[i].size();
            mxidx = i;
        }
    }


    set<ll> s;

    for(i = 0; i < 65; i++)
    {
        if(i == mxidx)
            continue;
        for(auto u : st[i])
            s.insert(u);
    }

    cout << s.size() << endl;
    for(auto u : s)
        cout << u << " ";

}
