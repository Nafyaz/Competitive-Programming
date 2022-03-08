#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int grid[1003][1003];
int newGrid[1003][1003];
vector<pair<pair<int, int>, int>> v;
map<pair<pair<int, int>, int>, int> mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, i, j, pos1, pos2, epochs = 8;

    cin >> n >> m;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            cin >> grid[i][j];

            if(i+1 <= n && j+1 <= m)
            {
                v.push_back({{i, j}, grid[i][j]});
                mp[{{i, j}, grid[i][j]}] = v.size() - 1;
            }
            if(i+1 <= n && j-1 >= 1)
            {
                v.push_back({{i, j-1}, grid[i][j]});
                mp[{{i, j-1}, grid[i][j]}] = v.size() - 1;
            }
            if(i-1 >= 1 && j+1 <= m)
            {
                v.push_back({{i-1, j}, grid[i][j]});
                mp[{{i-1, j}, grid[i][j]}] = v.size() - 1;
            }
            if(i-1 >= 1 && j-1 >= 1)
            {
                v.push_back({{i-1, j-1}, grid[i][j]});
                mp[{{i-1, j-1}, grid[i][j]}] = v.size() - 1;
            }
        }
    }


    while(epochs--)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(i+1 <= n && j+1 <= m && i-1 >= 1 && j-1 >= 1)
                {
                    pos1 = mp[{{i, j}, grid[i][j]}];
                    pos2 = mp[{{i-1, j-1}, grid[i-1][j-1]}];
                    if(grid[i][j] != grid[i-1][j-1] && pos1 < pos2)
                    {
                        mp[{{i, j}, grid[i][j]}] = pos2;
                        mp[{{i-1, j-1}, grid[i-1][j-1]}] = pos1;

                        swap(v[pos1], v[pos2]);
                        swap(pos1, pos2);
                    }
                }

                if(i+1 <= n && j+1 <= m && i-1 >= 1 && j+1 <= m)
                {
                    pos1 = mp[{{i, j}, grid[i][j]}];
                    pos2 = mp[{{i-1, j}, grid[i-1][j]}];

                    if(grid[i][j] != grid[i-1][j] && pos1 < pos2)
                    {
                        mp[{{i, j}, grid[i][j]}] = pos2;
                        mp[{{i-1, j}, grid[i-1][j]}] = pos1;

                        swap(v[pos1], v[pos2]);
                        swap(pos1, pos2);
                    }
                }

                if(i+1 <= n && j+1 <= m && i+1 <= n && j-1 >= 1)
                {
                    pos1 = mp[{{i, j}, grid[i][j]}];
                    pos2 = mp[{{i, j-1}, grid[i][j-1]}];

                    if(grid[i][j] != grid[i][j-1] && pos1 < pos2)
                    {
                        mp[{{i, j}, grid[i][j]}] = pos2;
                        mp[{{i, j-1}, grid[i][j-1]}] = pos1;

                        swap(v[pos1], v[pos2]);
                        swap(pos1, pos2);
                    }
                }
            }
        }
    }

    for(i = 0; i < v.size(); i++)
        cout << v[i].ff.ff << " " << v[i].ff.ss << " " << v[i].ss << "\n";

    for(i = 0; i < v.size(); i++)
    {
        newGrid[v[i].ff.ff][v[i].ff.ss] = v[i].ss;
        newGrid[v[i].ff.ff+1][v[i].ff.ss] = v[i].ss;
        newGrid[v[i].ff.ff][v[i].ff.ss+1] = v[i].ss;
        newGrid[v[i].ff.ff+1][v[i].ff.ss+1] = v[i].ss;
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            cout << newGrid[i][j] << " ";
//            if(newGrid[i][j] != grid[i][j])
//            {
//                cout << "-1";
//                return 0;
//            }
        }

        cout << "\n";
    }
}
