#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll b, k, n, grid[20][20], dp[131079][21];
string s;

ll func(ll i, ll p, ll rem)
{
//    cout << i << " " << log2(p) + 1 << " " << rem << endl;
    if(i == n && rem == 0)
    {
//        cout << rem << endl;
        return 1;
    }
    else if(i == n)
        return 0;

    if(dp[p][rem] != -1)
        return dp[p][rem];

    ll ret = 0;
    for(ll j = 0; j < n; j++)
    {
        if((p&(1LL << j)) == 0)
        {
//            cout << j << " " << i << " " << rem << endl;
            ret += func(i+1, p|(1LL << j), (rem+grid[j][i])%k);
        }
    }
//    cout << endl;
    return dp[p][rem] = ret;
}

int main()
{
    ll i, j, t, x, caseno = 0;
    cin >> t;
    while(t--)
    {
        cin >> b >> k >> s;
//        cout << b << endl;
        n = s.size();
        x = 1;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(s[j] >= '0' && s[j] <= '9')
                    grid[i][j] = ((s[j] - '0')*x)%k;
                else
                    grid[i][j] = ((s[j] - 'A' + 10)*x)%k;
            }
            x = (x*b)%k;
        }

//        for(i = 0; i < n; i++)
//        {
//            for(j = 0; j < n; j++)
//                cout << setw(3) << grid[i][j];
//            cout << endl;
//        }

//        memset(grid, 0, sizeof(grid));
        memset(dp, -1, sizeof(dp));

        cout << "Case " << ++caseno << ": " << func(0, 0, 0) << endl;
    }
}
