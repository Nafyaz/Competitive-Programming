#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

pair<ll, ll> Left, Right;
map<pair<ll, ll>, ll> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, n, i, st, ed, l, r, c;

    cin >> t;

    while(t--)
    {
        cin >> n;

        mp.clear();
        Left = {INT_MAX, -1};
        Right = {-1, -1};
        st = ed = -1;

        for(i = 0; i < n; i++)
        {
            cin >> l >> r >> c;

            if(mp.find({l, r}) == mp.end())
                mp[{l, r}] = c;
            else
                mp[{l, r}] = min(mp[{l, r}], c);

            if(st == -1 || l < st)
                st = l;
            if(ed == -1 || r > ed)
                ed = r;

            if(Left.ff > l)
                Left = {l, c};
            else if(Left.ff == l)
                Left.ss = min(Left.ss, c);

            if(Right.ff < r)
                Right = {r, c};
            else if(Right.ff == r)
                Right.ss = min(Right.ss, c);

            if(mp.find({st, ed}) == mp.end())
                cout << Left.ss + Right.ss << "\n";
            else
                cout << min(Left.ss + Right.ss, mp[{st, ed}]) << "\n";
        }
    }
}
