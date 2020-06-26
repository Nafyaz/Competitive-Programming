#include<bits/stdc++.h>
using namespace std;

int x, y, p;
string grid[35];
vector<int> adj[70];
int cap[70][70], par[70];
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1, 0, -1};

bool check(int a, int, b)
{
    if(a >= 0 && b >= 0 && a < x && b < y && grid[a][b] != '~')
        return 1;
    return 0;
}

void addedge(int a, int b, int c)
{
    adj[a].push_back(b);
    cap[a][b] = c;
}

int main()
{
    int i, j, k, s = 68, t = 69;
    while(cin >> x >> y >> p)
    {
        for(i = 0; i < 70; i++)
            adj[i].clear();
        memset(cap, 0, sizeof cap);

        for(i = 0; i < x; i++)
            cin >> grid[i];

        for(i = 0; i < x; i++)
        {
            for(j = 0; j < y; j++)
            {
                int node = i*y + j;
                if(grid[i][j] == '*')
                    addedge(s, node, 1);
                if(grid[i][j] == '#')
                    addedge(node, t, p);
                for(k = 0; k < 4; k++)
                {
                    int a = i+dirx[k], b = j+diry[k]
                    if(check(a, b))
                    {
                        int new_node = a*y + b;
                        if(grid[a][b] == '.')
                        {
                            addedge(node, new_node, 1);
                            addedge(new_node, node, 1);
                        }
                        else if(grid[a][b] == '@')
                        {

                        }
                    }
                }
            }
        }
    }
}
