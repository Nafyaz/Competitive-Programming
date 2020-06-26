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

int n, m, ri, rj, cnt, dir[4] = {1, 2, 0, 3};
string grid[55], s;

void walk()
{
    int u, p, i = ri, j = rj;
//    cout << s << endl;
    for(p = 0; p < s.size(); p++)
    {
        u = s[p] - '0';
        if(dir[u] == 0)
            i--;
        if(dir[u] == 1)
            i++;
        if(dir[u] == 2)
            j--;
        if(dir[u] == 3)
            j++;

//        cout << u << " " << dir[u] << " " << i << " " << j << " " << grid[i][j] << endl;

        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '#')
            return;

        if(grid[i][j] == 'E')
        {
            cnt++;
            return;
        }
    }
}

void permute(int l, int r)
{
    if(l == r)
    {
        walk();
        return;
    }
    for(int i = l; i <= r; i++)
    {
        swap(dir[i], dir[l]);
        permute(l+1, r);
        swap(dir[i], dir[l]);
    }
}

int main()
{
    int i, j, flag = 0;
    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        cin >> grid[i];
        if(!flag)
        {
            for(j = 0; j < m; j++)
            {
                if(grid[i][j] == 'S')
                {
                    flag = 1;
                    ri = i;
                    rj = j;
                    break;
                }
            }
        }
    }
//    cout << ri << " " << rj << endl;
    cin >> s;
    permute(0, 3);
    cout << cnt;
}
