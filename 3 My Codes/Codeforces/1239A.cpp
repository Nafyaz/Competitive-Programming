#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, i, f[100005];

    cin >> n >> m;

    if(n > m)
        swap(n, m);

    f[0] = 1, f[1] = 1;

    for(i = 2; i <= m; i++)
        f[i] = (f[i-1] + f[i-2]) % mod;

    cout << (2*(f[m]-1) + 2*f[n])%mod;
}
