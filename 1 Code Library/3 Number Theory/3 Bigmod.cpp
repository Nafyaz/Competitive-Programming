LL bigmod(LL a, LL p, LL MOD)
{
    if(p == 0)
        return 1%MOD;
    if(p == 1)
        return a%MOD;

    LL res = bigmod(a, p/2, MOD);
    res = (res*res)%MOD;
    if(p&1)
        return (a*res)%MOD;
    return res;
}

LL bigmod2(LL a, LL p, LL MOD)
{
    LL res = 1%MOD;
    while(p)
    {
        if(p&1)
            res = (res*a)%MOD;
        a = (a*a)%MOD;
        p /= 2;
    }
    return res;
}