#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n;
vector<int> adj[N];
vector<int> path;
int in[N];

void topsort()
{
    set<int> Q;
    int i;
    for(i = 1; i <= n; i++)
    {
        if(in[i] == 0)
            Q.insert(i);
    }

    while(!Q.empty())
    {
        int u = *Q.begin();
        Q.erase(Q.begin());
        path.push_back(u);
        for(auto x : adj[u])
        {
            in[x]--;
            if(in[x] == 0)
                Q.insert(x);
        }
    }
}

int main()
{
    int i, m;
    cin >> n >> m;
    for(i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }

//    for(i = 0; i <= n; i++)
//        cout << i << ": " << in[i] << endl;

    topsort();
    if(path.size() != n)
    {
        cout << "Sandro fails.";
        return 0;
    }

    for(i = 0; i < path.size(); i++)
        cout << path[i] << " ";
}
