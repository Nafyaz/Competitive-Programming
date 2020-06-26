#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("out.txt", "w", stdout);
    int q, n, m, i, j;
    scanf("%d", &q);
    while(q--)
    {
        int rob, colb, b;
        vector <int> row, col;

        scanf("%d %d", &n, &m);
        char grid[n+5][m+5];

        for(i = 0; i < n; i++)
            scanf("%s", grid[i]);

        rob = -1;
        for(i = 0; i < n; i++)
        {
            b = 0;
            for(j = 0; j < m; j++)
            {
                if(grid[i][j] == '*')
                    b++;
            }
            if(b > rob)
            {
                rob = b;
                row.clear();
                row.push_back(i);
            }
            else if(b == rob)
                row.push_back(i);
        }

        colb = -1;
        for(j = 0; j < m; j++)
        {
            b = 0;
            for(i = 0; i < n; i++)
            {
                if(grid[i][j] == '*')
                    b++;
            }
            if(b > colb)
            {
                colb = b;
                col.clear();
                col.push_back(j);
            }
            else if(b == colb)
                col.push_back(j);
        }

        int ans = n+m -rob-colb, flag = 1;

        for(i = 0; i < row.size(); i++)
        {
            for(j = 0; j < col.size(); j++)
            {
                if(flag && grid[row[i]][col[j]] == '.')
                {
                    ans--;
                    flag = 0;
                }
            }
        }

        printf("%d\n", ans);
    }
}
