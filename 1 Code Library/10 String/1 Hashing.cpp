LL base = 31;

LL n, p[MAXN];
LL preHash[MAXN];
LL sufHash[MAXN];

void initHash()
{
    LL i;

    p[0] = 1;
    for(i = 1; i < MAXN; i++)
        p[i] = (p[i-1] * base) % MOD;
}

void createHash (string s)
{
    LL i;

    n = s.size();

    for(i = 1; i <= n; i++)
    {
        preHash[i] = (preHash[i-1] * base) % MOD;
        preHash[i] = (preHash[i] + s[i-1] - 'a' + 1) % MOD;
    }

    for(i = n; i > 0; i--)
    {
        sufHash[i] = (sufHash[i+1] * base) % MOD;
        sufHash[i] = (sufHash[i] + s[i-1] - 'a' + 1) % MOD;
    }
}
