#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

map<ll, ll> Left, Right;
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
        Left.clear();
        Right.clear();
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

            if(Left.find(l) == Left.end())
                Left[l] = c;
            else
                Left[l] = min(Left[l], c);

            if(Right.find(r) == Right.end())
                Right[r] = c;
            else
                Right[r] = min(Right[r], c);

//            cout << "st: " << st << "; ed: " << ed << "\n";
//            cout << "Left:\n";
//            for(auto u : Left)
//                cout << u.ff << " " << u.ss << "\n";
////            cout << "\n";
//
//            cout << "Right:\n";
//            for(auto u : Right)
//                cout << u.ff << " " << u.ss << "\n";
////            cout << "\n";
//
//            cout << "mp:\n";
//            for(auto u : mp)
//                cout << u.ff.ff << " " << u.ff.ss << "; " << u.ss << "\n";
//            cout << "\n";


            if(mp.find({st, ed}) == mp.end())
                cout << Left[st] + Right[ed] << "\n";
            else
                cout << min(Left[st] + Right[ed], mp[{st, ed}]) << "\n";
        }
    }
}
