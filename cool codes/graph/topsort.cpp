#include<bits/stdc++.h>
using namespace std;

const int N=100005;
vector<int>V[N];
stack<int>st;
bool vis[N];

void dfs(int s)
{
    vis[s]=true;
    for(int x:V[s])
    {
        if(vis[x]==true) continue;
        dfs(x);
    }
    st.push(s);
}

int main()
{
    int node,edge;
    cin >> node >> edge;
    for(int i=1;i<=edge;i++)
    {
        int u,v;
        cin >> u >> v;
        V[u].push_back(v);
    }
    for(int i=1;i<=node;i++) if(vis[i]==false) dfs(i);
    //Stack Will hold topological order of the directed graph
    while(!st.empty()) {
            cout << st.top() << '\n';
            st.pop();
    }
}


