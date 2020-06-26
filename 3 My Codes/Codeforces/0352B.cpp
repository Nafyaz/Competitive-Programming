#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int func(vector<int> v)
{
    if(v.size() == 1)
        return 0;
    int ret = v[1] - v[0], i;
    for(i = 2; i < v.size(); i++)
    {
        if(v[i] - v[i-1] != ret)
            return -1;
    }

    return ret;
}

int main()
{
    int n, i, a;
    map<int, vector<int>> mp;

    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        mp[a].push_back(i);
    }

    vector<pair<int, int>> v;
    for(auto u : mp)
    {
        int dif = func(u.ss);
        if(dif != -1)
            v.push_back({u.ff, dif});
    }

    cout << v.size() << endl;
    for(auto u : v)
        cout << u.ff << " " << u.ss << endl;
}
