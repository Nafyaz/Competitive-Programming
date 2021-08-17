#include<bits/stdc++.h>
using namespace std;

int n, rMat[50009][6];
bool visited[50009];

bool isSup(int i, int j)
{
    int cnt = 0;
    for(int k = 1; k <= 5; k++)
    {
        if(rMat[i][k] < rMat[j][k])
            cnt++;
    }

    return cnt >= 3;
}

int dfs(int i)
{
    visited[i] = 1;

    for(int j = i+1; j <= n; j++)
    {
        if(isSup(j, i))
            return dfs(j);
    }

    return i;
}

int main()
{
    int t, i, j, ans;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
        {
            visited[i] = 0;
            for(j = 1; j <= 5; j++)
            {
                cin >> rMat[i][j];
            }
        }

        ans = dfs(1);

        for(i = 1; i <= n; i++)
        {
            if(ans == i)
                continue;
            if(isSup(i, ans))
            {
                ans = -1;
                break;
            }
        }

        cout << ans << "\n";
    }
}
/*
6
9 5 3 7 1
7 4 1 6 8
5 6 7 3 2
6 7 8 8 6
4 2 2 4 5
8 3 6 9 4
*/

