#include <bits/stdc++.h>
using namespace std;

const int INF=1e9+7;

int N;
int as[200005];

vector<int> edges[200005];

int dist[2][200005];
int q[200005];

void bfs(int* dist,int s)
{
    fill(dist,dist+N,INF);
    int qh=0,qt=0;
    q[qh++]=s;
    dist[s]=0;
    while(qt<qh)
    {
        int x=q[qt++];
        for(int y:edges[x])
        {
            if(dist[y]==INF)
            {
                dist[y]=dist[x]+1;
                q[qh++]=y;
            }
        }
    }
}

int main()
{
    int M,K;
    scanf("%d %d %d",&N,&M,&K);
    for(int i=0; i<K; i++)
    {
        scanf("%d",&as[i]);
        as[i]--;
    }
    sort(as,as+K);
    for(int i=0; i<M; i++)
    {
        int X,Y;
        scanf("%d %d",&X,&Y);
        X--,Y--;
        edges[X].push_back(Y);
        edges[Y].push_back(X);
    }
    bfs(dist[0],0);
    bfs(dist[1],N-1);
    vector<pair<int,int> > data;
    for(int i=0; i<K; i++)
    {
        data.emplace_back(dist[0][as[i]]-dist[1][as[i]],as[i]);
    }
    sort(data.begin(),data.end());
    int best=0;
    int mx=-INF;
    for(auto it:data)
    {
        int a=it.second;
        best=max(best,mx+dist[1][a]);
        mx=max(mx,dist[0][a]);
    }
    printf("%d\n",min(dist[0][N-1],best+1));
}
