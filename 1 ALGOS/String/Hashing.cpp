#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll base = 31, mod = 1e9+7;

ll n, p[100009];
ll preHash[100009];
ll sufHash[100009];

int main()
{
    ll i;
    string s;

    p[0] = 1;
    for(i = 1; i < 100009; i++)
        p[i] = (p[i-1] * base) % mod;

    cin >> s;

    n = s.size();

    for(i = 1; i <= n; i++)
    {
        preHash[i] = (preHash[i-1] * base) % mod;
        preHash[i] = (preHash[i] + s[i-1] - 'a' + 1) % mod;
    }

    for(i = n; i > 0; i--)
    {
        sufHash[i] = (sufHash[i+1] * base) % mod;
        sufHash[i] = (sufHash[i] + s[i-1] - 'a' + 1) % mod;
    }
}
