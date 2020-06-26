#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second

int n, x, y, loop[4] = {-1, 0, 1, 0};
char nxt, last;
char grid[15][15];
bool vis[15][15];
int dis[15][15];

bool push_this(pair<int, int> p)
{
    int a = p.ff, b = p.ss;
    if(a < 0 || a >= n || b < 0 || b >= n || vis[a][b] == 1 || grid[a][b] == '#')
        return 0;
    if(grid[a][b] >= 'A' && grid[a][b] <= 'Z')
    {
        if(grid[a][b] != nxt)
            return 0;
    }
    return 1;
}

void bfs()
{
    int i;

    queue <pair<int, int> > q;
    pair<int, int> p, p2;
    p = {x, y};
    q.push(p);
    vis[x][y] = 1;
    dis[x][y] = 0;

    while(!q.empty())
    {
        p = q.front();
        q.pop();

        for(i = 0; i < 4; i++)
        {
            p2 = {p.ff + loop[i], p.ss + loop[(i+1)%4]};
//            printf("%d %d %d\n", p2.ff, p2.ss, push_this(p2));

            if(push_this(p2))
            {
                vis[p2.ff][p2.ss] = 1;
                dis[p2.ff][p2.ss] = dis[p.ff][p.ss] + 1;
                q.push(p2);
                if(grid[p2.ff][p2.ss] == nxt)
                {
                    grid[x][y] = '.';
                    nxt ++;
                    x = p2.ff;
                    y = p2.ss;
                    return;
                }
            }
        }

    }
}

int main()
{
//    freopen("out.txt", "w", stdout);
    int T, i, j, caseno = 0;
    map <char, pair<int, int>> mp;
    scanf("%d", &T);
    while(T--)
    {
        mp.clear();
        scanf("%d", &n);
        nxt = 'B';
        last = 'A' - 1;
        for(i = 0; i < n; i++)
        {
            scanf("%s", grid[i]);
            for(j = 0; j < n; j++)
            {
                if(grid[i][j] >= 'A' && grid[i][j] <= 'Z')
                    mp[grid[i][j]] = {i, j};
            }
        }

        i = 0;
        for(auto x : mp)
        {
            grid[x.ss.ff][x.ss.ss] = 'A' + i;
            i++;
        }


        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                last = max(last, grid[i][j]);
                if(grid[i][j] == 'A')
                {
                    x = i;
                    y = j;
                }
            }
        }

        int flag = 0, ans = 0;
        char temp;
        while(nxt <= last)
        {
            memset(vis, 0, sizeof(vis));
            memset(dis, 0x3f3f3f3, sizeof(dis));
            temp = nxt;

            bfs();
            if(temp == nxt)
            {
                flag = 1;
                break;
            }
            ans += dis[x][y];
        }
        flag? printf("Case %d: Impossible\n", ++caseno) : printf("Case %d: %d\n", ++caseno, ans);
    }
}
