#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

vector<int> adj[100005];
pair<int, int> p[100005];
map<pair<int, int>, int> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, i, j, a, b, k = 0, color, reserved;

    cin >> n;

    for(i = 1; i < n; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        p[i] = {a, b};

        k = max({k, (int)adj[a].size(), (int)adj[b].size()});
    }

    cout << k << "\n";

    for(i = 1; i <= n; i++)
    {
        color = 1;
        reserved = 0;
        for(auto u : adj[i])
        {
            if(mp.find({i, u}) != mp.end())
            {
                reserved = mp[{i, u}];
                break;
            }
        }

        for(auto u : adj[i])
        {
            if(mp.find({i, u}) == mp.end())
            {
                if(color == reserved)
                    color++;

                mp[{i, u}] = mp[{u, i}] = color;

                color ++;
            }
        }
    }

    for(i = 1; i < n; i++)
        cout << mp[p[i]] << "\n";
}

