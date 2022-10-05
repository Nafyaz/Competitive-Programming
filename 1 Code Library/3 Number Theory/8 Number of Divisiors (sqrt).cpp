bool flag[MAXN];
vector<LL> primes;

void sieve() {}

LL NOD(LL n)
{
    LL i, c, ret = 1;

    for(i = 0; primes[i]*primes[i] <= n; i++)
    {
        for(c = 0; n % primes[i] == 0; c++)
            n /= primes[i];
        ret *= (c+1);
    }

    if(n > 1)
        ret = ret << 1;

    return ret;
}
