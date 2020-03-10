#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int n, st[100009], et[100009], vis[100009], Time, filled[100009];
vector<int> adj[100009];
set<pair<int, int> > myset;

void dfs(int node, int par)
{
    vis[node] = 1;
    st[node] = ++Time;

    for(auto u : adj[node])
    {
        if(vis[u] || u == par)
            continue;
        dfs(u, node);
    }

    et[node] = ++Time;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, caseno = 0, i, j, u, v;
    cin >> t;
    while(t--)
    {
        cin >> n;

        myset.clear();
        for(i = 1; i <= n; i++)
        {
            adj[i].clear();
            st[i] = et[i] = vis[i] = filled[i] = 0;
        }

        for(i = 1; i < n; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(i = 1; i <= n; i++)
            sort(adj[i].begin(), adj[i].end());

        Time = 0;
        dfs(1, -1);

        for(i = 1; i <= n; i++)
            myset.insert({et[i], i});

        cout << "Case " << ++caseno << ":" << "\n";

        int q, type, x;
        set<pair<int, int> >::iterator it;
        queue<pair<int, int> > myqueue;
        pair<int, int> p;

        cin >> q;

        while(q--)
        {
            cin >> type;
//                    cout << "lol0";
            if(type == 1)
            {
                cin >> u >> x;

//                    cout << "lol1";                for(it = myset.lower_bound({st[u], -1}); it != myset.end() && x--; it++)
                {                    p = (*it);
//                    cout << st[p.ss] << " " << et[u] << "\n";
                    if(st[p.ss] > et[u])
                        break;
                    filled[p.ss] = 1;
                    myqueue.push(p);
                }

                while(!myqueue.empty())
                {
                    myset.erase(myqueue.front());
                    myqueue.pop();
                }

            }
            else
            {
                cin >> u;
                cout << filled[u] << "\n";
            }

//            for(auto u : myset)
//                cout << "{" << u.ff << ", " << u.ss << "} ";
//            cout << "\n";
//            for(i = 1; i <= n; i++)
//                cout << setw(4) << i << " ";
//            cout << "\n";
//            for(i = 1; i <= n; i++)
//                cout << setw(4) << filled[i] << " ";
//            cout << "\n";
        }

     }
}

/*
1
11
1 2
1 3
1 8
2 4
2 5
5 6
5 7
3 11
8 9
8 10

8
1 1 1
1 2 2
2 5
1 1 1
2 5
1 1 4
2 3
2 10
*/
