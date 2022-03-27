#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m;
string grid[102];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, i, j, flag;

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(i = 0; i < n; i++)
            cin >> grid[i];

        flag = 1;
        for(i = 0; i+1 < n && flag; i++)
        {
            for(j = 0; j+1 < m && flag; j++)
            {
                if((grid[i][j]-'0') + (grid[i+1][j]-'0') + (grid[i][j+1]-'0') + (grid[i+1][j+1]-'0') == 3)
                    flag = 0;
            }
        }

        cout << (flag? "YES\n" : "NO\n");
    }
}
