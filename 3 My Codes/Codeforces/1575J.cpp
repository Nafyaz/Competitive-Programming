#include<bits/stdc++.h>
using namespace std;

int grid[1003][1003];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, i, j, c;

    cin >> n >> m >> k;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    while(k--)
    {
        cin >> c;

        for(i = 0; i < n;)
        {
            if(grid[i][c-1] == 1)
            {
                grid[i][c-1] = 2;
                c++;
            }
            else if(grid[i][c-1] == 2)
                i++;
            else
            {
                grid[i][c-1] = 2;
                c--;
            }
        }

        cout << c << " ";
    }
}
