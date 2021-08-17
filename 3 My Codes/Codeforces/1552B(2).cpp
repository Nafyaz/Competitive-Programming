#include<bits/stdc++.h>
using namespace std;

int n, rMat[50009][6], racers[50009];
bool visited[50009];
map<pair<int, int>, int> mp;

bool isSup(int i, int j)
{
    if(mp.find({i, j}) != mp.end())
        return mp[{i, j}];

    int cnt = 0;
    for(int k = 1; k <= 5; k++)
    {
        if(rMat[i][k] < rMat[j][k])
            cnt++;
    }

    if(cnt >= 3)
    {
        mp[{i, j}] = 1;
        mp[{j, i}] = 0;
    }
    else
    {
        mp[{i, j}] = 0;
        mp[{j, i}] = 1;
    }

    return mp[{i, j}];
}

int dfs(int i)
{
    if(visited[i])
        return -1;

    visited[i] = 1;

    for(int j = 1; j <= n; j++)
    {
        if(i == j)
            continue;
        if(isSup(j, i))
            return dfs(j);
    }

    return i;
}

int main()
{
    int t, i, j, x, ans;

    cin >> t;

    while(t--)
    {
        mp.clear();
        cin >> n;

        for(i = 1; i <= n; i++)
        {
            visited[i] = 0;
            racers[i] = i;
            for(j = 1; j <= 5; j++)
            {
                cin >> rMat[i][j];
            }
        }

        random_shuffle(racers, racers+n);

        ans = -1;
        for(i = 1; i <= n; i++)
        {
            x = racers[i];
            if(!visited[x])
            {
                ans = dfs(x);
                if(ans != -1)
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
