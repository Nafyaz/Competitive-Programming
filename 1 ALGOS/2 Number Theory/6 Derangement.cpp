ll D[MAXN];
ll getDerange(ll n)
{
    if(n == 1)
        return D[1] = 0;
    if(n == 2)
        return D[2] = 1;
    if(D[n] != 0)
        return D[n];

    return (n-1) * (getDerange(n-1) + getDerange(n-2));
}