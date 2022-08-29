bool flag[MAXN];
vector<LL> primes;

void sieve()
{
    LL i, j;

    flag[2] = 1;
    for(i = 3; i < MAXN; i += 2)
        flag[i] = 1;

    for(i = 3; i * i < MAXN; i+=2)
    {
        if(flag[i])
        {
            for(j = i*i; j < MAXN; j += 2*i)
                flag[j] = 0;
        }
    }

    for(i = 2; i < MAXN; i++)
    {
        if(flag[i])
            primes.push_back(i);
    }
}