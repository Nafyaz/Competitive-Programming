#include<bits/stdc++.h>
using namespace std;

int n, x[25], dp[25];

void call(int i, int cost)
{
    if(i > n || i < 0)
        return;

    if(dp[i] != -1 && dp[i] <= cost)
        return;

    dp[i] = cost;
    call(i+1, cost+1);
    call(i+x[i], cost+1);
}

int main()
{
    int T, i;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
        {
            cin >> x[i];
        }

        memset(dp, -1, sizeof dp);
        call(0, 0);

        cout << dp[n] << "\n";
    }
}
