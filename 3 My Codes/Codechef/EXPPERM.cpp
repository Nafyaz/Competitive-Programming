#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ll T, n, ans;

    cin >> T;

    while(T--)
    {
        cin >> n;

        ans = n+1;
        ans = (ans * (n-1)) % mod;
        ans = (ans * (3*n+2)%mod)%mod;
        ans = (ans * 83333334LL) % mod;

        cout << ans << "\n";
    }
}
