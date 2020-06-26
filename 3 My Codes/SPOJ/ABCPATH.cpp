#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

bool vis[55][55];
vector<pair<int, int> > v;
string grid[55];
int h, w;
int dirx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int diry[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int dfs(int i, int j, char c)
{
//    cout << i << " " << j << " " << c << endl;
    vis[i][j] = 1;

    int x, y, k, ret = 1;
    for(k = 0; k < 8; k++)
    {
        x = i + dirx[k];
        y = j + diry[k];
        if(x < 0 || x >= h || y < 0 || y >= w || vis[x][y] || grid[x][y] != c+1)
            continue;
        ret = max(ret, 1 + dfs(x, y, c+1));
    }

    return ret;
}

int main()
{
    int i, j, ans, caseno = 0;
    while(1)
    {
        cin >> h >> w;
        if(!h && !w)
            break;

        memset(vis, 0, sizeof vis);
        v.clear();
        for(i = 0; i < h; i++)
        {
            cin >> grid[i];
            for(j = 0; j < w; j++)
            {
                if(grid[i][j] == 'A')
                    v.push_back({i, j});
            }
        }

        ans = 0;
        for(auto u : v)
        {
            ans = max(ans, dfs(u.ff, u.ss, 'A'));
        }

        cout << "Case " << ++caseno << ": " << ans << endl;
    }
}
