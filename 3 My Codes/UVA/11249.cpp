#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v;
ll dp[100009];

int main()
{
    int t, k, q, a, b, i;

    cin >> t;

    while(t--)
    {
        cin >> k;

        memset(dp, 0, sizeof dp);

        p = 0;
        for(i = 1; i <= 100000; i++)
        {
            if(!dp[i])
            {
                dp[i] = dp[p] + k + (i-p+1);
                if(dp[i] <= 100000)
                    dp[dp[i]] = i;
                p=i;
            }
        }

        cin >> q;

        while(q--)
        {
            cin >> a >> b;

            if(dp[a]==b||dp[b]==a)
                cout << "LOSING\n";
            else
                cout << "WINNING\n";
        }

        cout << "\n";
    }
}
