#include<bits/stdc++.h>
using namespace std;

int n, m;


int edges(int i, int j)
{
    int ret = 4;
    if(i == 0 || i == n-1)
        ret--;
    if(j == 0 || j == m-1)
        ret--;
    return ret;
}

int main()
{
    int t, i, j;
    int grid[309][309], flag;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        flag = 1;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] > edges(i, j))
                    flag = 0;
            }
        }

        if(!flag)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
                cout << edges(i, j) << " ";
            cout << endl;
        }
    }
}
