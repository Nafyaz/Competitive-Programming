/*
    Author : RAJON BARDHAN
    AUST CSE 27th Batch
    All my programming success are dedicated to my mom , dad , little sister madhobi , teachers , friends and love TANIA SULTANA RIMY

    Problem Name : CAPCITY - Capital City ( SPOJ )
    ALGORITHM : SCC
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define memo(a,b) memset(a,b,sizeof(a))
#define INF 1e9
#define EPS 1e-8
#define PI 3.14159265358979323846

typedef long long ll ;
typedef unsigned long long ull ;

/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

int N, M, dt[100000+10], ft[100000+10], ct[100000+10], outdegree[100000+10], cycle = 1, t = 1 ;
bool visit[100000+10] ;
vector <int> G[100000+10], GT[100000+10], Q ;

void dfs1(int u)
{
    visit[u] = true ;
    dt[u] = t++ ;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i] ;
        if(!visit[v])
            dfs1(v);
    }
    ft[u] = t++ ;
    Q.pb(u);
}

void dfs2(int u,int cmp)
{
    visit[u] = false ;
    ct[u] = cycle ;
    for(int i=0; i<GT[u].size(); i++)
    {
        int v = GT[u][i] ;
        if(visit[v]&&cmp>ft[v])
            dfs2(v,cmp);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d",&N,&M);
    while( M-- )
    {
        int u, v ;
        scanf("%d%d",&u,&v);
        G[u].pb(v);
        GT[v].pb(u);
    }
    for(int i=1; i<=N; i++)
        if(!visit[i])
            dfs1(i);
    for(int i=Q.size()-1; i>=0; i--)
        if(visit[Q[i]])
        {
            dfs2(Q[i],ft[Q[i]]);
            cycle++;
        }
    for(int u=1; u<=N; u++)
    {
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i] ;
            if(ct[u]!=ct[v])
                outdegree[ct[u]]++;
        }
    }
    int count = 0 ;
    for(int i=1; i<cycle; i++)
        if(outdegree[i]==0)
            count++;
    if(count>1)
        puts("0");
    else
    {
        vector <int> V ;
        for(int i=1; i<=N; i++)
            if(outdegree[ct[i]]==0)
                V.pb(i);
        printf("%d\n",V.size());
        for(int i=0; i<V.size(); i++)
        {
            if(i!=0)
                printf(" ");
            printf("%d",V[i]);
        }
        puts("");
    }
    return 0;
}
