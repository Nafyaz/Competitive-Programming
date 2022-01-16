#include<bits/stdc++.h>
using namespace std;

string grid[51];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, m, r, c, i, j;
    bool anyBlack;

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> r >> c;

        anyBlack = 0;
        for(i = 0; i < n; i++)
        {
            cin >> grid[i];

            for(j = 0; !anyBlack && j < m; j++)
            {
                if(grid[i][j] == 'B')
                    anyBlack = 1;
            }
        }

        if(!anyBlack)
        {
            cout << "-1\n";
            continue;
        }

        if(grid[r-1][c-1] == 'B')
        {
            cout << "0\n";
            continue;
        }

        anyBlack = 0;
        for(i = 0; i < n; i++)
        {
            if(grid[i][c-1] == 'B')
                anyBlack = 1;
        }
        for(i = 0; i < m; i++)
        {
            if(grid[r-1][i] == 'B')
                anyBlack = 1;
        }

        if(anyBlack)
            cout << "1\n";
        else
            cout << "2\n";
    }
}
