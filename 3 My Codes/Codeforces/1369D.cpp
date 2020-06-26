#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define N 2000009

ll dp[N];

int main()
{
    int t, n, i;
    for(i = 3; i < N; i++)
        dp[i] = (2 * dp[i-2] + dp[i-1] + (i%3 == 0? 4 : 0)) % mod;

    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << dp[n] << endl;
    }
}
