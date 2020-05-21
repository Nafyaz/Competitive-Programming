#include<bits/stdc++.h>

using namespace std;
#define white 0
#define gray 1
#define black 2

vector<int>adj[100000];
bool visited[100000]= {false};
int dis[100000]= {0},fin[100000]= {0},tim=0;
stack<int>st;
int color[100000]={0};
bool hasCycle=false;
bool compare(int a,int b)
{
    if(a>b) return true;
    return false;
}
void dfs(int x)
{
    if(visited[x]) return;
    visited[x] = true;
    color[x]=gray;
    tim++;
    dis[x]=tim;
    for(int i=0;i<adj[x].size();i++)
    {
        int u=adj[x][i];
        if(visited[u]&&color[u]==gray&&color[x]==gray){
            hasCycle=true;
        }
        else if(!visited[u]) dfs(adj[x][i]);
    }
    color[x]=black;
    tim++;
    fin[x]=tim;
    st.push(x);
}

int main()
{
    int n,m,i,u,v;
    cin>>n>>m;
    while(!st.empty())
        st.pop();
    for(i=0; i<m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(i=1; i<=n; i++)
    {
        sort(adj[i].begin(),adj[i].end(),compare);
    }
    for(i=n; i>=1; i--)
    {
        if(!visited[i])
            dfs(i);
    }
    if(hasCycle)
        cout<<"Sandro fails."<<endl;
    else{
        for(i=0; i<n-1; i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<st.top()<<endl;
    }


}
