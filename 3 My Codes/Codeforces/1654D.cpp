#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mod 998244353

#define N 100005
bool flag[N];
vector<ll> primes;
void sieve()
{
    ll i, j;

    flag[2] = 1;
    for(i = 3; i < N; i += 2)
        flag[i] = 1;

    for(i = 3; i * i < N; i+=2)
    {
        if(flag[i])
        {
            for(j = i*i; j < N; j += 2*i)
                flag[j] = 0;
        }
    }

    for(i = 2; i < N; i++)
    {
        if(flag[i])
            primes.push_back(i);
    }
}


class factorizedNumber
{
public:
    map<ll, ll> freq;

    factorizedNumber()
    {
//        for(auto p : primes)
//            freq[p] = 0;
    }

    factorizedNumber(ll v)
    {
        ll i, p, c;
        for(i = 0; i < primes.size() && primes[i]*primes[i] <= v; i++)
        {
            p = primes[i];
            for(c = 0; v%p == 0; c++)
                v /= p;

            freq[p] = c;
        }

        if(v > 1)
            freq[v] = 1;
    }

    factorizedNumber operator*(factorizedNumber& x)
    {
        factorizedNumber ret;

        for(auto u : freq)
            ret.freq[u.ff] = u.ss;
        for(auto u : x.freq)
            ret.freq[u.ff] -= u.ss;

        return ret;
    }

    factorizedNumber operator/(factorizedNumber& x)
    {
        factorizedNumber ret;

        for(auto u : freq)
            ret.freq[u.ff] = u.ss;
        for(auto u : x.freq)
            ret.freq[u.ff] -= u.ss;

        return ret;
    }

    factorizedNumber GCD(factorizedNumber& x)
    {
        factorizedNumber ret;

        for(auto p : primes)
            ret.freq[p] = min(freq[p], x.freq[p]);

        return ret;
    }

    factorizedNumber LCM(factorizedNumber& x)
    {
        factorizedNumber ret;

        for(auto p : primes)
            ret.freq[p] = max(freq[p], x.freq[p]);

        return ret;
    }

};

ll deFactorize(factorizedNumber x)
{
    ll ret = 1;
    for(auto u : x.freq)
    {
        while(u.ss)
        {
            ret = (ret*u.ff) % mod;
            u.ss--;
        }
    }

    return ret;
}

pair<factorizedNumber, factorizedNumber> amount[200005];
vector<pair<ll, pair<factorizedNumber, factorizedNumber>>> adj[200005];

void dfs(ll s, ll p)
{
    factorizedNumber x = amount[s].ff;
    factorizedNumber y = amount[s].ss;

//    cout << "In dfs of " << s << "\n";

    for(auto u : adj[s])
    {
        if(u.ff == p)
            continue;

        factorizedNumber xNew = x*u.ss.ff;
        factorizedNumber yNew = y*u.ss.ss;
        factorizedNumber g = xNew.GCD(yNew);

        xNew = xNew / g;
        yNew = yNew / g;

        amount[u.ff] = {xNew, yNew};

        dfs(u.ff, s);
    }
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    sieve();

    ll t, n, i, j, k, g, l, x, y, ans, add;

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(i = 1; i <= n; i++)
            adj[i].clear();

        for(k = 1; k < n; k++)
        {
            cin >> i >> j >> x >> y;

            factorizedNumber X = factorizedNumber(x);
            factorizedNumber Y = factorizedNumber(y);

            factorizedNumber G = X.GCD(Y);
            X = X / G;
            Y = Y / G;

            adj[i].push_back({j, {Y, X}});
            adj[j].push_back({i, {X, Y}});
        }

        amount[1] = {factorizedNumber(1), factorizedNumber(1)};
        dfs(1, -1);

        factorizedNumber L;
        for(i = 1; i <= n; i++)
            L = L.LCM(amount[i].ss);


        ans = 0;
        for(i = 1; i <= n; i++)
        {
            cout << i << "\n";
            add = deFactorize(L / amount[i].ss * amount[i].ff);
            ans = (ans + add) % mod;
        }

        cout << ans << "\n";
    }
}
