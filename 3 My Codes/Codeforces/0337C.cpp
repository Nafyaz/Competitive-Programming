#include<bits/stdc++.h>
using namespace std;
long long mod = 1000000009;

long long bigmod(long long a, long long b)
{
    if(b == 0)
        return 1;
    long long res = bigmod(a, b>>1);
    res = (res*res)%mod;
    if(b&1)
        res = (res*a)%mod;
    return res;
}

int main()
{
    long long n, m, k, x;
    cin >> n >> m >> k;

    x = max(0LL, m - (n/k*(k-1) + n%k));

    cout << (((bigmod(2, x+1) - 2)*k)%mod + m - x*k + mod)%mod;

}
