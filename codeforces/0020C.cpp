#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define ll long long
#define ss second
#define ff first

ll n, m;
vector <pair<ll, ll> > adj[N];
ll dis[N], parent[N];

void djikstra(ll s)
{
    ll i;
    for(i = 0; i <= n; i++)
        dis[i] = LLONG_MAX;

    dis[s] = 0;
    multiset <pair<ll, ll> > ms;
    ms.insert({0, s});
    pair<ll, ll> p;

    ll node;

    while(!ms.empty())
    {
        p = *ms.begin();
        ms.erase(ms.begin());

        node = p.ss;
        for(auto u : adj[node])
        {
            if(dis[u.ss] > dis[node] + u.ff)
            {
                dis[u.ss] = dis[node] + u.ff;
                ms.insert(u);
                parent[u.ss] = node;
            }
        }
    }
}

int main()
{
    ll u, v, w;
    scanf("%lld %lld", &n, &m);

    while(m--)
    {
        scanf("%lld %lld %lld", &u, &v, &w);
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    djikstra(1);

    if(dis[n] == LLONG_MAX)
    {
        printf("-1");
        return 0;
    }

    stack<ll> st;
    ll temp = n;

    while(temp != 0)
    {
        st.push(temp);
        temp = parent[temp];
    }

    while(!st.empty())
    {
        printf("%lld ", st.top());
        st.pop();
    }
}
