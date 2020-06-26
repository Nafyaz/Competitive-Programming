#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int main()
{
    ll t, i, j, n, m, caseno = 0, lcs[31][31], dp[31][31];
    string a, b;
    cin >> t;
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        memset(lcs, 0, sizeof(lcs));

        cin >> a >> b;
        n = a.size(), m = b.size();

        for(i = 0; i <= n; i++)
            dp[i][0] = 1;
        for(i = 0; i <= m; i++)
            dp[0][i] = 1;

        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(a[i-1] == b[j-1])
                {
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                    if(lcs[i-1][j] > lcs[i][j-1])
                        dp[i][j] = dp[i-1][j];
                    else if(lcs[i-1][j] < lcs[i][j-1])
                        dp[i][j] = dp[i][j-1];
                    else
                        dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        cout << "Case " << ++caseno << ": " << n+m-lcs[n][m] << " " << dp[n][m] << endl;
//        for(i = 0; i <= n; i++)
//        {
//            for(j = 0; j <= m; j++)
//                cout << lcs[i][j] << " ";
//            cout << endl;
//        }
//        cout << endl << endl;
//        for(i = 0; i <= n; i++)
//        {
//            for(j = 0; j <= m; j++)
//                cout << dp[i][j] << " ";
//            cout << endl;
//        }
    }
}

