#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, n, a, ans = 0, mod = 998244353, p, digit, sum;

    cin >> n;
    ans = 0;
    for(i = 0; i < n; i++)
    {
        cin >> a;

        p = 1;
        while(a)
        {
            digit = a%10;
            ans = (ans + digit*p)%mod;

            p = (p*10)%mod;
            ans = (ans + digit*p)%mod;

            a /= 10;
            p = (p*10)%mod;
        }
    }
    cout << (ans * n)%mod << "\n";
}
