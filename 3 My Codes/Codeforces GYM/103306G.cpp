#include<bits/stdc++.h>
using namespace std;

int len[1003][1003], ans;

int n, m;
string grid[1003];

int dirr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int diry[8] = {0, -1, -1, -1, 0, 1, 1, 1};

bool isValid(int r, int c, char ch)
{
    if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == ch)
        return 1;
    else
        return 0;
}

int dfs(int r, int c)
{
    int ret = 1;

    for(int i = 0; i < 8; i++)
    {
        int r2 = r + dirr[i];
        int c2 = c + diry[i];

        if(isValid(r2, c2, grid[r][c]+1))
        {
            if(len[r2][c2] != -1)
                ret = max(ret, len[r2][c2] + 1);
            else
                ret = max(ret, dfs(r2, c2) + 1);
        }
    }

    return len[r][c] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int i, j, ans = 0;

    cin >> n >> m;

    for(i = 0; i < n; i++)
        cin >> grid[i];

    memset(len, -1, sizeof len);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(len[i][j] == -1)
                dfs(i, j);

            ans = max(ans, len[i][j]);
        }
    }

    cout << ans;
}

