#include<bits/stdc++.h>
using namespace std;

bool func(vector<int> v)
{
    int posn = -1, pos1 = -1, mx = -1, mn = INT_MAX, i;

    for(i = 0; i < v.size(); i++)
    {
        if(v[i] == 1)
            pos1 = i;
        if(v[i] == v.size())
            posn = i;

        if(pos1 != -1)
            mx = max(mx, v[i]);
        if(posn == -1)
            mn = min(mn, v[i]);
    }

    if(pos1 < posn)
        return 1;
    else if(pos1 == v.size()-1 || posn == 0)
        return 0;

    map<int, int> mp;

    mp[mn] = 0;
//    cout << mp.size() << endl;
    for(i = posn + 1; i < pos1; i++)
        mp[v[i]] = i - posn;
//    cout << mp.size() << endl;
    mp[mx] = mp.size()-1;
//    cout << mp.size() << endl;


//    for(auto u : mp)
//        cout << u.first << " " << u.second << endl;
//    cout << endl;

    vector<int> v2(mp.size());
    i = 0;
    for(auto u : mp)
        v2[u.second] = ++i;

    return func(v2);
}

int main()
{
    int t, n, i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> v(n);
        for(i = 0; i < n; i++)
            cin >> v[i];

        cout << (func(v)? "YES\n" : "NO\n");
    }
}
