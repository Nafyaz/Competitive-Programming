#include<bits/stdc++.h>
using namespace std;

int par[15];
int Find(int x)
{
    if(par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    par[x] = y;
}

int main()
{
    int t, n, a, i, j, mn, mx, cnt[15];
    vector<int> adj[15];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < 15; i++)
        {
            par[i] = i;
            cnt[i] = 0;
            adj[i].clear();
        }


        for(i = 0; i < n; i++)
        {
            cin >> a;
            adj[a].push_back(i);
            for(j = max(0, a-2); j <= a+2; j++)
            {

                for(auto u : adj[j])
                    Union(u, i);
            }
//            for(j = 0; j < n; j++)
//                cout << Find(j) << " ";
//            cout << endl;
        }


        for(i = 0; i < n; i++)
            cnt[Find(i)]++;
//
//        for(i = 0; i < n; i++)
//            cout << cnt[i] << " ";
//
        mn = 15, mx = -1;
        for(i = 0; i < n; i++)
        {
            if(cnt[i])
            {
                mn = min(mn, cnt[i]);
                mx = max(mx, cnt[i]);
            }
        }
//
        cout << mn << " " << mx << endl;
    }
}
