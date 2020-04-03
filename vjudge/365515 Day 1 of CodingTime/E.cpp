#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int h, w, x, y, inf = 1e5;
int vis[25][25], dirx[] = {0, 1, 0, -1}, diry[] = {1, 0, -1, 0};
string grid[25];

int bfs(int i, int j)
{
    int a, b, c, ret = 0;
    pair<pair<int, int>, int> p;
    queue<pair<pair<int, int>, int> > q;
    q.push({{i, j}, 0});
    vis[i][j] = 1;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
//        cout << p.ff.ff << " " << p.ff.ss << endl;
        for(int k = 0; k < 4; k++)
        {
            a = p.ff.ff + dirx[k];
            b = p.ff.ss + diry[k];
            c = p.ss;

            if(a >= 0 && a < h && b >= 0 && b < w && grid[a][b] == '.' && vis[a][b] == 0)
            {
                q.push({{a, b}, c+1});
                vis[a][b] = 1;
                ret = max(ret, c+1);
            }
        }
    }
    return ret;
}

int main()
{
//    freopen("in.txt", "r", stdin);
    int i, j;
    cin >> h >> w;
    for(i = 0; i < h; i++)
        cin >> grid[i];

    int ans = 0;

    for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            if(grid[i][j] == '#')
                continue;
            memset(vis, 0, sizeof(vis));
//            cout << "new: " << i << " " << j << endl;
            ans = max(ans, bfs(i, j));
        }
    }

    cout << ans;
}
