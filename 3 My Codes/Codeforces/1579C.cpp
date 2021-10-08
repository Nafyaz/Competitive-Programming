#include<bits/stdc++.h>
using namespace std;

string grid[10];

int n, m, k;

bool isTick(int i, int j)
{
    int x, y1, y2, k2;

    for(x = i-1, k2 = 0; x >= 0; x--)
    {
        y1 = j-k2-1;
        y2 = j+k2+1;
        if(y1 >= 0 && (grid[x][y1] == '*' || grid[x][y1] == '#') && y2 < m && ((grid[x][y2] == '*' || grid[x][y2] == '#')))
            k2++;
    }

    return k2 >= k;
}

void tickAck(int i, int j)
{
    grid[i][j] = '#';

    int x, y1, y2, k2;

    for(x = i-1, k2 = 0; x >= 0; x--)
    {
        y1 = j-k2-1;
        y2 = j+k2+1;
        if(y1 >= 0 && (grid[x][y1] == '*' || grid[x][y1] == '#') && y2 < m && (grid[x][y2] == '*' || grid[x][y2] == '#'))
        {
//            cout << x << " " << y1 << " " << y2 << "\n";
            grid[x][y1] = '#';
            grid[x][y2] = '#';
            k2++;
        }
        else
            break;
    }
}

void solve()
{
    int i, j;
    cin >> n >> m >> k;

    for(i = 0; i < n; i++)
        cin >> grid[i];

//    tickAck(3, 5);
//    for(i = 0; i < n; i++)
//        cout << grid[i] << "\n";

    for(i = n-1; i >= 0; i--)
    {
        for(j = 0; j < m; j++)
        {
            if(grid[i][j] == '*' || grid[i][j] == '#')
            {
                if(isTick(i, j))
                    tickAck(i, j);
                else if(grid[i][j] == '*')
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
}

int main()
{
    int t;

    cin >> t;

    while(t--)
    {
        solve();
    }
}
