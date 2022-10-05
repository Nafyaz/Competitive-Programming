LL inv[MAXN];

//only if mod is prime and gcd(a, mod) = 1
LL invmod(LL a, LL mod)
{
    return bigmod(a, mod-2, mod);
}

LL egcd(LL a, LL m, LL& x, LL& y)
{
    if(m == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    LL x1, y1;
    LL d = egcd(m, a%m, x1, y1);

    x = y1;
    y = x1 - y1*(a/m);

    return d;
}

//when gcd(a, mod) = 1
LL invod2(LL a, LL mod)
{
    LL x, y;
    egcd(a, mod, x, y);

    return (x%mod + mod) % mod;
}

//when N is prime
void allinvmod()
{
    LL i;
    inv[1] = 1;
    for(i = 2; i < N; i++)
        inv[i] = ((-N/i*inv[N%i]) % N + N) % N;
}
