#include<bits/stdc++.h>
using namespace std;

long long bigmod(long long a, long long b, long long m)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a%m;

    long long x = bigmod(a, b/2, m), y = 1;
    if(b%2 == 1)
        y = a%m;

    return ((x*x)%m * y)%m;
}

int main()
{
    int h, w, i, j;
    cin >> h >> w;

    int hi[h], wi[w], grid[h][w];

    memset(grid, -1, sizeof(grid));

    for(i = 0; i < h; i++)
        cin >> hi[i];
    for(i = 0; i < w; i++)
        cin >> wi[i];

    for(i = 0; i < h; i++)
    {
        for(j = 0; j < hi[i] ; j++)
            grid[i][j] = 1;
        if(j < w)
            grid[i][j] = 0;
    }

    for(i = 0; i < w; i++)
    {
        for(j = 0; j < wi[i]; j++)
        {
            if(grid[j][i] == 0)
            {
                cout << 0;
                return 0;
            }
            grid[j][i] = 1;
        }
        if(j < h)
        {
            if(grid[j][i] == 1)
            {
                cout << 0;
                return 0;
            }
            grid[j][i] = 0;
        }

    }

    int cnt = 0;

    for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            if(grid[i][j] == -1)
                cnt++;
        }
    }

    cout << bigmod(2, cnt, 1000000007);
}
