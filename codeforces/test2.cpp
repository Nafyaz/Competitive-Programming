#include <bits/stdc++.h>
#define maxn 200005

vector<int>conj[maxn];
int n,k,u,v,depth[maxn]= {0},size[maxn]= {0},det[maxn];
long long ans=0;

int cmp(int a,int b)
{
    return a>b;
}
int dfs(int u,int f)
{
    depth[u]=depth[f]+1;
    size[u]=1;
    for (int i=0; i<conj[u].size(); ++i)
    {
        if ((v=conj[u][i])==f)
            continue;
        size[u]+=dfs(v,u);
    }
    det[u]=size[u]-depth[u];
    return size[u];
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1; i<n; ++i)
    {
        scanf("%d%d",&u,&v);
        conj[u].push_back(v);
        conj[v].push_back(u);
    }
    dfs(1,0);
    nth_element(det+1,det+n-k,det+n+1,cmp);
    for (int i=1; i<=n-k; ++i)
        ans+=det[i];
    cout<<ans;
    return 0;
}
