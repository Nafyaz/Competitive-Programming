bool flag[MAXN];
vector<int> primes;
ll phi[MAXN];

void sieve() {}

ll findPhi(ll n)
{
    if(phi[n] != 0)
        return phi[n];

    ll i, cnt, ret = n, temp = n;
    for(i = 0; primes[i] * primes[i] <= n; i++)
    {
        for(cnt = 0; n % primes[i] == 0; cnt++)
            n /= primes[i];

        if(cnt > 0)
            ret = ret / primes[i] * (primes[i] - 1);
    }

    if(n > 1)
        ret = ret / n * (n - 1);

    return phi[temp] = ret;
}

void sievephi()
{
    ll i, j;
    for(i = 1; i < MAXN; i++)
        phi[i] = i;

    for(i = 2; i < MAXN; i++)
    {
        if(phi[i] == i)
        {
            for(j = i; j < MAXN; j += i)
                phi[j] = phi[j] / i * (i - 1);
        }
    }
}

void segsievephi(ll a, ll b)
{
    ll i, j, cnt;

    for(i = a; i <= b; i++)
    {
        phi[i-a] = i;
        val[i-a] = i;
    }

    for(auto p : primes)
    {
        if(p * p > b)
            break;

        for(i = (a + p - 1) / p * p; i <= b; i += p)
        {
            for(cnt = 0; val[i - a] % p == 0; cnt++)
                val[i - a] /= p;

            if(cnt)
                phi[i - a] = phi[i - a] / p * (p - 1);
        }
    }

    for(i = a; i <= b; i++)
    {
        if(val[i - a] > 1)
            phi[i - a] = phi[i - a] / val[i - a] * (val[i - a] - 1);
    }
}
