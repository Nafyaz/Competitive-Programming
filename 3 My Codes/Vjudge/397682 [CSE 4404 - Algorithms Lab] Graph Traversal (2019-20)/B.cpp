/*
Check and remove this section while coding
1. Get rid of toolbars except compiler and main. Enable only logs and status.
2. Use C++17 in global compiler settings.
3. Turn on Wall, Wextra, Wshadow in warnings.
4. Make tab spout 4 spaces
*/

/*
ID: nafis.f1
TASK:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define pii pair<int, int>

int dis[8][8];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool is_valid(int x, int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int bfs(pii s, pii t)
{
    queue<pii> q;
    dis[s.ff][s.ss] = 0;
    q.push(s);

    int i, x, y, new_x, new_y;
    while(!q.empty())
    {
        pii node = q.front();
        q.pop();

        x = node.ff;
        y = node.ss;

        for(i = 0; i < 8; i++)
        {
            new_x = x + dx[i];
            new_y = y + dy[i];

            if(is_valid(new_x, new_y) && dis[new_x][new_y] == -1)
            {
                q.push({new_x, new_y});
                dis[new_x][new_y] = dis[x][y] + 1;
            }
        }
    }

    return dis[t.ff][t.ss];
}

int main()
{
    string xx, yy;
    while(cin >> xx >> yy)
    {
        pair<int, int> s = {xx[0] - 'a', xx[1] - '1'};
        pair<int, int> t = {yy[0] - 'a', yy[1] - '1'};

        memset(dis, -1, sizeof dis);
        cout << "To get from " << xx << " to " << yy << " takes " << bfs(s, t) << " knight moves.\n";
    }

}
