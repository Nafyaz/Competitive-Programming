#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, i2, j2, k, n, m, ans, flag;
    string grid[109];

    int diri[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dirj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    while(1)
    {
        cin >> n >> m;
        if(!n && !m)
            break;

        for(i = 0; i < n; i++)
            cin >> grid[i];

        ans = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                flag = 0;
                if(grid[i][j] == '*')
                    flag = 1;

                for(k = 0; k < 8 && flag; k++)
                {
                    i2 = i + diri[k];
                    j2 = j + dirj[k];

                    if(i2 < 0 || i2 >= n || j2 < 0 || j2 >= m)
                        continue;

                    if(grid[i2][j2] == '*')
                        flag = 0;
                }

                ans += flag;
            }
        }

        cout << ans << "\n";
    }
}
