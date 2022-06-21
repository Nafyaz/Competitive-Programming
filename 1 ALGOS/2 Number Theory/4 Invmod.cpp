ll inv[MAXN];

//only if mod is prime and gcd(a, mod) = 1
ll invmod(ll a, ll mod)
{
    return bigmod(a, mod-2, mod);
}

ll egcd(ll a, ll m, ll& x, ll& y)
{
    if(m == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll d = egcd(m, a%m, x1, y1);

    x = y1;
    y = x1 - y1*(a/m);

    return d;
}

//when gcd(a, mod) = 1
ll invod2(ll a, ll mod)  
{
    ll x, y;
    egcd(a, mod, x, y);

    return (x%mod + mod) % mod;
}

//when N is prime
void allinvmod() 
{
    ll i;
    inv[1] = 1;
    for(i = 2; i < N; i++)
        inv[i] = ((-N/i*inv[N%i]) % N + N) % N;
}