bool flag[MAXN];
LL leastFactor[MAXN];
vector<LL> primes;
LL sod[MAXN];

void sieve() {}

LL linSOD(LL n)
{
    LL lf, c, p, ret = 1;

    while(n > 1)
    {
        lf = leastFactor[n];
        p = 1;

        for(c = 0; n%lf == 0; c++)
        {
            n /= lf;
            p *= lf;
        }

        ret *= (p*lf - 1)/(lf - 1);
    }

    return ret;
}

LL SOD(LL n)
{
    LL i, c, ret = 1;

    for(i = 0; primes[i]*primes[i] <= n; i++)
    {
        LL p = 1;
        for(c = 0; n % primes[i] == 0; c++)
        {
            n /= primes[i];
            p = p * primes[i];
        }
        ret *= (p * primes[i] - 1) / (primes[i] - 1);
    }

    if(n > 1)
        ret *= (n*n - 1) / (n - 1);
    return ret;
}

void allSOD()
{
    LL i, j;

    for(i = 1; i < MAXN; i++)
    {
        for(j = i; j < MAXN; j += i)
            sod[j] += i;
    }
}
