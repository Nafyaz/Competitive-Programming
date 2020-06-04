#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, j, k, n, m, a, b;
    int grid[55][55], cnt[55];

    cin >> t;
    while(t--)
    {
        cin >> n >> m >> a >> b;

        if(n * a != m * b)
        {
            cout << "NO\n";
            continue;
        }

        memset(grid, 0, sizeof grid);
        memset(cnt, 0, sizeof cnt);

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < a; j++)
            {
                grid[i][j] = 1;
                cnt[j]++;
            }
        }

        for(i = 0; i < m; i++)
        {
            for(j = 0; j < m; j++)
            {
                while(cnt[i] > b && cnt[j] < b)
                {
                    for(k = 0; k < n; k++)
                    {
                        if(grid[k][i] == 1 && grid[k][j] == 0)
                        {
                            swap(grid[k][i], grid[k][j]);
                            cnt[i]--;
                            cnt[j]++;
                            break;
                        }
                    }
                }
            }
        }

        cout << "YES\n";
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
                cout << grid[i][j];
            cout << endl;
        }
    }
}
