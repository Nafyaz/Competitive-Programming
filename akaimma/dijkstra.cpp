#include<bits/stdc++.h>
using namespace std;

#define ll                  long long
#define fast                ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb                  push_back

int main()
{
    fast;
    ll n,i,j,k,temp,ans,q,a,b,w,u,v;
    vector<pair<ll,ll> >adj[510];
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>w;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
    }
    cin>>u>>q;
    ll dis[510];
    for(i = 0; i < 510; i++)
        dis[i]=1;
    priority_queue<pair<ll,ll> >pq;
    pair<ll,ll>p;
    dis[u]=0;
    pq.push({0,u});
    while(pq.size()){
        p=pq.top();
        pq.pop();
        for(auto i : adj[p.second])
        {
            if(dis[i.first] == 1 || dis[p.second] - i.second > dis[i.first])
            {
                dis[i.first] = dis[p.second] - i.second;
                pq.push({dis[i.first],i.first});
            }
        }
    }
    while(q--)
    {
        cin>>v;
        if(dis[v]==1)
            cout<<"NO PATH\n";
        else
            cout<<-1*dis[v]<<'\n';
    }
    return 0;
}
