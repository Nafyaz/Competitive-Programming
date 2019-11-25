#include <bits/stdc++.h>
using namespace std;

const int N=100005;
vector<int>V[N];
vector<int>path;
int indegree[N];

void topsort(int n)
{
    queue<int>Q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0) Q.push(i);
    }
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        path.push_back(u);
        for(int i=0;i<V[u].size();i++)
        {
            int x=V[u][i];
            indegree[x]--;
            if(indegree[x]==0) Q.push(x);
        }
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        V[u].push_back(v);
        indegree[v]++;
    }
    topsort(n);
}
