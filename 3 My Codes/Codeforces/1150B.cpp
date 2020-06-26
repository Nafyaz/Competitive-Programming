#include<bits/stdc++.h>
using namespace std;

int n;
string grid[60];

bool isClear(int i, int j)
{
    if(i <= 0 || j <= 0 || i >= n - 1 || j >= n - 1)
        return 0;
    if(grid[i][j] == '.' && grid[i-1][j] == '.' && grid[i+1][j] == '.' && grid[i][j-1] == '.' && grid[i][j+1] == '.')
        return 1;
    return 0;
}

void put(int i, int j)
{
    grid[i][j] = '#';
    grid[i-1][j] = '#';
    grid[i+1][j] = '#';
    grid[i][j-1] = '#';
    grid[i][j+1] = '#';
}

int main()
{
    int i, j;

    cin >> n;
    for(i = 0; i < n; i++)
        cin >> grid[i];


    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(isClear(i, j))
                put(i, j);
        }
    }

    int ans = 1;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(grid[i][j] == '.')
                ans = 0;
        }
    }

    cout << (ans? "YES" : "NO");
}
