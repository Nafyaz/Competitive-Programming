ll bigmod(ll a, ll p, ll MOD)
{
    if(p == 0)
        return 1%MOD;
    if(p == 1)
        return a%MOD;

    ll res = bigmod(a, p/2, MOD);
    res = (res*res)%MOD;
    if(p&1)
        return (a*res)%MOD;
    return res;
}

ll bigmod2(ll a, ll p, ll MOD)
{
    ll res = 1%MOD;
    while(p)
    {
        if(p&1)
            res = (res*a)%MOD;
        a = (a*a)%MOD;
        p /= 2;
    }
    return res;
}