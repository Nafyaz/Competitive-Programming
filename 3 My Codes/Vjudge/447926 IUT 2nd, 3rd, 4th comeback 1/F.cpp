#include<bits/stdc++.h>
using namespace std;
#define maxsize 50

int n;
vector<int> adjL[maxsize];
int adjM[maxsize][maxsize];

bool dfs(int s, int len, int e)
{
    if(len == n && s == e)
        return 1;

    if(len > n)
        return 0;

    for(auto u : adjL[s])
    {
        if(adjM[s][u])
        {
            adjM[s][u]--;
            if(u != s)
                adjM[u][s]--;

            if(dfs(u, len+1, e) == 1)
                return 1;

            adjM[s][u]++;
            if(u != s)
                adjM[u][s]++;
        }
    }

    return 0;
}

int main()
{
    int m, i, a, b, s1, s2, e1, e2;

    while(cin >> n)
    {
        if(!n)
            break;

        for(i = 0; i < maxsize; i++)
            adjL[i].clear();
        memset(adjM, 0, sizeof adjM);

        cin >> m;

        cin >> s1 >> s2;
        cin >> e1 >> e2;

        while(m--)
        {
            cin >> a >> b;

            adjL[a].push_back(b);

            adjM[a][b]++;

            if(a != b)
            {
                adjL[b].push_back(a);
                adjM[b][a]++;
            }
        }

        cout << (dfs(s2, 0, e1)? "YES\n" : "NO\n");

    }
}
