#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll C[40][40], f[10];

ll nCr(ll n, ll r)
{
    if(r > n || r < 0)
        return 0;
    if(r == 0 || r == n)
        return 1;
    if(r == 1 || r == n-1)
        return n;
    if(C[n][r] != 0)
        return C[n][r];

    C[n][r] = nCr(n-1, r-1) + nCr(n-1, r);

    return C[n][r];
}

ll fact(ll n)
{
    if(n < 0)
        return 0;
    if(n <= 1)
        return 1;
    if(f[n] != 0)
        return f[n];

    f[n] = n*fact(n-1);
    return f[n];
}

int main()
{
//    freopen("out.txt", "w", stdout);
    ll t, caseno = 0, n, k;
    cin >> t;

    while(t--)
    {
        cin >> n >> k;
        cout << "Case " << ++caseno << ": " << fact(k) * nCr(n, k) * nCr(n, k) << endl;
    }
}
