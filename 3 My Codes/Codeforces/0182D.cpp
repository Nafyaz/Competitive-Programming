#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s[2];
ll z[2][100005];

void zAlgo(ll x)
{
    ll n = s[x].size(), i, l, r;

    z[x][0] = 0;
    for(i = 1, l = 0, r = 0; i < n; i++)
    {
        if(i <= r)
            z[x][i] = min(r-i+1, z[x][i-l]);

        while(i + z[x][i] < n && s[x][i+z[x][i]] == s[x][z[x][i]])
            z[x][i]++;

        if(i + z[x][i] -1 > r)
        {
            l = i;
            r = i + z[x][i] - 1;
        }
    }
}

ll NOD(ll n)
{
    ll i = 2, ret = 1, c;

    for(i = 2; i*i <= n; i++)
    {
        for(c = 0; n%i == 0; c++)
            n /= i;

        ret *= (c+1);
    }

    if(n > 1)
        ret *= 2;

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll i, mnDivisor[2];

    cin >> s[0] >> s[1];

    zAlgo(0);
    zAlgo(1);

    mnDivisor[0] = s[0].size();
    for(i = 1; i < s[0].size(); i++)
    {
        if(i + z[0][i] == s[0].size() && z[0][i]%i == 0)
        {
            mnDivisor[0] = i;
            break;
        }
    }

    mnDivisor[1] = s[1].size();
    for(i = 1; i < s[1].size(); i++)
    {
        if(i + z[1][i] == s[1].size() && z[1][i]%i == 0)
        {
            mnDivisor[1] = i;
            break;
        }
    }

    if(s[0].substr(0, mnDivisor[0]) != s[1].substr(0, mnDivisor[1]))
    {
        cout << 0;
        return 0;
    }

    ll quotient[2] = {s[0].size()/mnDivisor[0], s[1].size()/mnDivisor[1]};
    ll gcd = __gcd(quotient[0], quotient[1]);

    cout << NOD(gcd);
}
