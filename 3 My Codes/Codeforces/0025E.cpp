#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll base = 31, mod = 1e9+7;
ll p[100009];

string s[4];
vector<ll> Hash[4];

ll modmul(ll a, ll b)
{
//    if(b == 1)
//        return a;
//
//    ll ret = modmul(a, b>>1);
//
//    ret = (ret << 1) % mod;
//
//    if(b&1)
//        ret = (ret + a) % mod;
//
//    return ret;

    return a*b;
}

ll add(ll i, ll j)
{
    ll szi, szj, n, HashI, HashJ;

    szi = s[i].size();
    szj = s[j].size();

    n = min(szi, szj);

    for(; n; n--)
    {
        HashI = (((Hash[i][szi] - modmul(Hash[i][szi - n], p[n])) % mod) + mod) % mod;
        HashJ = Hash[j][n];

        if(HashI == HashJ)
            break;
    }

    return n;
}

bool isSubstr(ll i, ll j)
{
    ll szi, szj, HashI, HashJ;

    szi = s[i].size();
    szj = s[j].size();

    if(szi < szj)
        return 0;

    for(ll k = szj; k < szi; k++)
    {
        HashI = (((Hash[i][k] - modmul(Hash[i][k-szj], p[szj])) % mod) + mod) % mod;
        HashJ = Hash[j][szj];

        if(HashI == HashJ)
            return 1;
    }

    return 0;
}

void createHash(ll i)
{
    Hash[i].clear();

    ll j;

    Hash[i].push_back(0);

    for(j = 0; j < s[i].size(); j++)
    {
        Hash[i].push_back((Hash[i][j]*base) % mod);

        Hash[i][j+1] = (Hash[i][j+1] + (s[i][j] - 'a' + 1)) % mod;
    }
}

int main()
{
    ll i, n;

    p[0] = 1;
    for(i = 1; i < 100009; i++)
        p[i] = (p[i-1] * base) % mod;

    cin >> s[0] >> s[1] >> s[2];

    for(i = 0; i < 3; i++)
        createHash(i);

    ll ans = INT_MAX, len, perm[3] = {0, 1, 2};

    while(1)
    {
        if(isSubstr(perm[0], perm[1]))
        {
            n = s[perm[1]].size();
            s[3] = s[perm[0]];
            len = s[3].size();
        }
        else
        {
            n = add(perm[0], perm[1]);
            s[3] = s[perm[0]] + s[perm[1]].substr(n);
            len = s[3].size();
        }

        createHash(3);

        if(isSubstr(3, perm[2]))
        {
            n = s[perm[2]].size();
            len = s[3].size();
        }
        else
        {
            n = add(3, perm[2]);
            len = s[3].size() + s[perm[2]].size() - n;
        }

        ans = min(ans, len);

        if(next_permutation(perm, perm+3) == 0)
            break;
    }

    cout << ans;
}
