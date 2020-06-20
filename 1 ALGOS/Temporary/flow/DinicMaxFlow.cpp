#include<bits/stdc++.h>
using namespace std;

#define ll              long long
#define pb              push_back
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))

struct edge
{
    int to,rev,f,cap;
};

const int maxnodes=10005;
int s,t,lev[maxnodes],q[maxnodes],work[maxnodes];
vector<edge>g[maxnodes];

inline void addEdge(int u,int v,int w)
{
    edge a= {v,g[v].size(),0,w};
    edge b= {u,g[u].size(),0,0};
    g[u].pb(a);
    g[v].pb(b);
}

bool dinic_bfs()
{
    MEM(lev,-1);
    lev[s]=0;
    int idx=0;
    q[idx++]=s;
    REP(i,idx)
    {
        int u=q[i];
        REP(j,g[u].size())
        {
            edge &e=g[u][j];
            if(lev[e.to]<0 and e.f<e.cap)
            {
                lev[e.to]=lev[u]+1;
                q[idx++]=e.to;
            }
        }
    }
    return lev[t]>=0;
}

int dinic_dfs(int u,int f)
{
    if(u==t) return f;
    for(int &i=work[u];i<g[u].size();i++)
    {
        edge &e=g[u][i];
        if(e.cap<=e.f) continue;
        if(lev[e.to]==lev[u]+1)
        {
            int flow=dinic_dfs(e.to,min(f,e.cap-e.f));
            if(flow>0)
            {
                e.f+=flow;
                g[e.to][e.rev].f-=flow;
                return flow;
            }
        }
    }
    return 0;
}

int maxFlow()
{
    int ret=0;
    while(dinic_bfs())
    {
        MEM(work,0);
        while(int flow=dinic_dfs(s,INT_MAX))
            ret+=flow;
    }
    return ret;
}

int main()
{
    int n,m;
    cin >> n >> m >> s >> t;
    REP(i,m)
    {
        int u,v,w;
        cin >> u >> v >> w;
        addEdge(u,v,w);
        addEdge(v,u,w); //If bidirectional
    }
    cout << maxFlow();
    return 0;
}
