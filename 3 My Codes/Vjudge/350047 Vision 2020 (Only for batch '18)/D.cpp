#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int grid[15][15], flag, vis[15][15];
int dirr[] = {-1, 0, 1, 0}, dirc[] = {0, -1, 0, 1};
string s;

void dfs(int r, int c)
{
//    cout << r << " " << c << endl;
    if(flag || grid[r][c] == 10)
    {
        flag = 1;
        return;
    }
    vis[r][c] = 1;

    int i, j, r2, c2;
    for(i = 0; i < 4; i++)
    {
        r2 = r + dirr[i];
        c2 = c + dirc[i];

        if(!flag && !vis[r2][c2] && r2 >= 1 && r2 <= 12 && c2 >= 1 && c2 <= 12 && grid[r2][c2] != 1)
        {
            if(i == 0)
                s += 'U';
            if(i == 1)
                s += 'L';
            if(i == 2)
                s += 'D';
            if(i == 3)
                s += 'R';
            dfs(r2, c2);
        }
    }


}

int main()
{
    int r, c, l;

    grid[3][3] = 10;
    grid[3][10] = 10;
    grid[10][3] = 10;
    grid[10][10] = 10;

    grid[6][6] = 1;
    grid[6][7] = 1;
    grid[7][6] = 1;
    grid[7][7] = 1;

    grid[9][2] = 1;
    grid[9][3] = 1;
    grid[10][2] = 1;

    grid[9][10] = 1;
    grid[9][11] = 1;
    grid[10][10] = 1;

    cin >> l;
    while(l--)
    {
        memset(vis, 0, sizeof(vis));
        s = "";
        flag = 0;
        cin >> r >> c;
        dfs(r, c);

        cout << s.size() << endl << s << endl;
    }
}
