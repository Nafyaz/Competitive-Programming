#include<bits/stdc++.h>
using namespace std;

int n, e, vis[50000], flag;
vector<int> adj[50000];

void dfs(int x, int cnt)
{
    if(flag)return;

    vis[x] = cnt;

    for(auto node : adj[x])
    {
        if(vis[node] == cnt)
        {
            flag = 1;
            return;
        }
            dfs(node, cnt);
    }
}

int main()
{
    int t, caseno = 0, u, v, i, j;
    map <string, int> mp;
    string us, vs;
    scanf("%d", &t);
    while(t--)
    {
        mp.clear();
        for(i = 0; i < n; i++)
            adj[i].clear();
        n = 0;
        memset(vis, 0, sizeof(vis));
        flag = 0;

        scanf("%d", &e);
        while(e--)
        {
            cin >> us >> vs;

            if(mp.find(us) == mp.end())
            {
                u = n++;
                mp[us] = u;
            }
            if(mp.find(vs) == mp.end())
            {
                v = n++;
                mp[vs] = v;
            }
            adj[mp[us]].push_back(mp[vs]);
        }

//        for(i = 0; i < 4; i++)
//        {
//            printf("%d: ", i);
//            for(auto x : adj[i])
//                printf("%d ", x);
//            printf("\n");
//        }

        int cnt = 0;
        for(i = 0; i < n; i++)
        {
            if(!vis[i])
                dfs(i, ++cnt);
            if(flag)
                break;
        }

        flag? printf("Case %d: No\n", ++caseno) : printf("Case %d: Yes\n", ++caseno);
    }
}
