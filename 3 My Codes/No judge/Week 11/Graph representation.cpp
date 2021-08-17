#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int n, m;
vector<pair<int, int>> edges;
int adjMat[102][102];
vector<int> adjL[102];

vector<pair<int, pair<int, int>>> edges2;
vector<pair<int, int>> adjL2[102];

int main()
{
    int i, a, b, w;
    cin >> n >> m;

    for(i = 0; i < m; i++)
    {
        cin >> a >> b;
        edges.push_back({min(a, b), max(a, b)});

        adjMat[a][b] = 1;
        adjMat[b][a] = 1;

        adjL[a].push_back(b);
        adjL[b].push_back(a);

        cin >> w;
        edges2.push_back({w, {a, b}});

        adjMat[a][b] = w;
        adjMat[b][a] = w;

        adjL2[a].push_back({w, b});
        adjL2[b].push_back({w, a});
    }
}
