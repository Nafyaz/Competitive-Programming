ll leastFactor[MAX];
bool isComposite[MAX];
vector<ll> primes;

void linSieve()
{
    ll i, j;
    for (i = 2; i < MAX; ++i)
    {
        if (leastFactor[i] == 0)
        {
            leastFactor[i] = i;
            primes.push_back(i);
        }
        for (j = 0; j < (ll)primes.size() && primes[j] <= leastFactor[i] && i*primes[j] < MAXN; ++j)
        {
            leastFactor[i * primes[j]] = primes[j];
        }
    }
}

void linSieve2()
{
    ll i, j;
    for(i = 2; i < N; i++)
    {
        if (!isComposite[i])
            primes.push_back(i);

        for(j = 0; j < (ll)primes.size() && i*primes[j] < MAXN; j++)
        {
            isComposite[i * primes[j]] = 1;
            if(i % primes[j] == 0)
                break;
        }
    }
}