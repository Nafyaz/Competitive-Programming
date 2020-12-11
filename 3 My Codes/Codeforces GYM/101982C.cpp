#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define MOD 998244353

ll n, k, a[110], dp[110][110];

ll call(ll i, ll j)
{
    if(n - i < k - j)
        return dp[i][j] = 0;
    if(i == n)
    {
        if(j == k)
            return dp[i][j] = 1;
        else
            return dp[i][j] = 0;
    }
    if(dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = (call(i+1, j) + (a[i] * call(i+1, j+1)) % MOD) % MOD;
}

int main()
{
    ll i, j, x;
    map<ll, ll> freq;
    cin >> n >> k;
    for(i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }

    i = 0;
    n = freq.size();
    for(auto u : freq)
        a[i++] = u.ss;

//    if(k > n)
//    {
//        cout << 0;
//        return 0;
//    }

//    for(i = 0; i < n; i++)
//        cout << a[i] << " ";
//    cout << "\n";


    memset(dp, -1, sizeof dp);
    cout << call(0, 0) << "\n";

//    for(i = 0; i < 6; i++)
//    {
//        for(j = 0; j < 6; j++)
//            cout << setw(4) << dp[i][j] << " ";
//        cout << "\n";
//    }
}

