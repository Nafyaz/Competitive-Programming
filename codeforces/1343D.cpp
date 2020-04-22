#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int t, n, m, i, j, k, a[200009], dp[100009][3], dp2[100009][3][2], mx, mn;
vector<pair<int, int> > v;

int main()
{
    cin >> t;
    while(t--)
    {
        v.clear();
        cin >> n >> m;
        for(i = 1; i <= n; i++)
            cin >> a[i];
        for(i = 1; i <= n/2; i++)
            v.push_back({a[i], a[n-i+1]});

        for(i = 0; i < 3; i++)
        {
            dp2[0][i][0] = INT_MIN;
            dp2[0][i][1] = INT_MAX;
        }

//        for(auto u : v)
//            cout << u.ff << " " << u.ss << endl;

        for(i = 1; i <= n/2; i++)
        {
            for(j = 0; j < 3; j++)
            {
                dp[i][j] = n+1;

                if(j == 0)
                    mn = mx = v[i-1].ff + v[i-1].ss;

                else if(j == 1)
                {
                    mx = max(v[i-1].ff, v[i-1].ss) + m;
                    mn = min(v[i-1].ff, v[i-1].ss) + 1;
                }
                else
                {
                    mx = 2*m;
                    mn = 2;
                }

                for(k = 0; k < 3; k++)
                {
                    if(max(dp2[i-1][k][0], mn) <= min(dp2[i-1][k][1], mx) && dp[i-1][k] + j < dp[i][j])
                    {
                        dp2[i][j][0] = max(dp2[i-1][k][0], mn);
                        dp2[i][j][1] = min(dp2[i-1][k][1], mx);
                        dp[i][j] = dp[i-1][k] + j;
                    }
                }
            }
        }
//        cout << "lol " << n << " " << m << "\n";
//        for(j = 0; j < 3; j++)
//        {
//            for(i = 0; i <= n/2; i++)
//                cout << dp[i][j] << " ";
//            cout << endl;
//        }
//        for(j = 0; j < 3; j++)
//        {
//            for(i = 0; i <= n/2; i++)
//                cout << dp2[i][j][0] << ", " << dp2[i][j][1] << "   ";
//            cout << endl;
//        }
        cout << min({n/2, dp[n/2][0], dp[n/2][1], dp[n/2][2]}) << endl;
    }
}
