#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second

ll n, m, k;
ll dis[100005], cnt[100005];
ll ans;
vector<pair<ll, ll>>adj[100005];

bool mark[100005];

void Spfa()
{
    ll i;
    for(i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
        cnt[i] = 0;
    }

    queue<ll> Q;
    dis[1] = 0;
    Q.push(1);
    mark[1] = true;

    while(!Q.empty())
    {
        ll node = Q.front();
        Q.pop();
        mark[node] = false;

        for(auto u : adj[node])
        {
            if(dis[u.ss] > dis[node] + u.ff)
            {
                dis[u.ss] = dis[node] + u.ff;
                cnt[u.ss] = 0;
                if(mark[u.ss] == false)
                {
                    Q.push(u.ss);
                    mark[u.ss] = true;
                }
            }
            else if(dis[u.ss] == dis[node] + u.ff)
                cnt[u.ss]++;
        }
    }
}


int main()
{
    ll i;
    cin >> n >> m >> k;
    while(m--)
    {
        ll u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({x, v});
        adj[v].push_back({x, u});
    }

    ll train[n+1];
    memset(train, 0, sizeof train);

    while(k--)
    {
        ll s, y;
        cin >> s >> y;
        if(train[s] == 0)
            train[s] = y;
        else
        {
            if(train[s] > y)
                train[s] = y;
            ans++;
        }
    }
    for(i = 2; i <= n; i++)
    {
        if(train[i] == 0)
            continue;
        adj[1].push_back({train[i], i});
        adj[i].push_back({train[i], 1});
    }

    Spfa();

    for(i = 2; i <= n; i++)
    {
        if(train[i] != 0)
        {
            if(dis[i] < train[i])
                ans++;
            else if(dis[i] == train[i])
            {
                if(cnt[i] > 0)
                    ans++;
            }
        }
    }

    cout << ans << "\n";
}
