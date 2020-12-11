#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll coins[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
ll dp[30009][11];

ll call(ll x, ll n)
{
    if(dp[x][n] != -1)
        return dp[x][n];
    if(x == 0)
        return 1;
    if(n == 0)
        return 0;

    ll ret = call(x, n-1);

    if(x >= coins[n-1])
        ret += call(x - coins[n-1], n);

    return dp[x][n] = ret;
}

int main()
{
    ll x;
    string s;
    memset(dp, -1, sizeof dp);

    while(1)
    {
        cin >> s;
        if(s == "0.00")
            break;
        x = (ll)((stof(s) + 0.0001)*100);

//        cout << x << "\n";
        cout << setw(6) << s << setw(17) << max(0LL, call(x, 11)) << "\n";
    }
}
