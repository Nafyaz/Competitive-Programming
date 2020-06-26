#include<bits/stdc++.h>
using namespace std;

bool vis[109];
int n, tin[109], low[109], timer;
string n2s[109];
vector<int> adj[109];
set<string> AP;

void dfs(int v, int p = -1)
{
    vis[v] = 1;
    tin[v] = low[v] = ++timer;

    int child = 0;

    for(auto to : adj[v])
    {
        if(to == p)
            continue;
        if(!vis[to])
        {
            child++;
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(p != -1 && low[to] >= tin[v])
                AP.insert(n2s[v]);
        }
        else
            low[v] = min(low[v], tin[to]);
    }

    if(p == -1 && child > 1)
        AP.insert(n2s[v]);

}

void findAP()
{
    AP.clear();
    timer = 0;
    for(int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        tin[i] = -1;
        low[i] = -1;
    }

    for(int i = 1; i <= n; i++)
        dfs(i);
}
int main()
{
//    freopen("out.txt", "w", stdout);
    map<string, int> s2n;
    string s, t;
    int  r, caseno = 0, i;

    while(cin >> n)
    {
        if(!n)
            break;

        if(caseno)
            cout << endl;

        s2n.clear();

        for(i = 1; i <= n; i++)
        {
            adj[i].clear();
            cin >> s;
            s2n[s] = i;
            n2s[i] = s;
        }

        cin >> r;
        while(r--)
        {
            cin >> s >> t;
            adj[s2n[s]].push_back(s2n[t]);
            adj[s2n[t]].push_back(s2n[s]);
        }

        findAP();

        cout << "City map #" << ++caseno << ": " << AP.size() << " camera(s) found\n";
        for(auto u : AP)
            cout << u << endl;
    }

}
/*
6
sugarloaf
maracana
copacabana
ipanema
corcovado
lapa
7
ipanema copacabana
copacabana sugarloaf
ipanema sugarloaf
maracana lapa
sugarloaf maracana
corcovado sugarloaf
lapa corcovado
5
guanabarabay
downtown
botanicgarden
colombo
sambodromo
4
guanabarabay sambodromo
downtown sambodromo
sambodromo botanicgarden
colombo sambodromo
0
*/
