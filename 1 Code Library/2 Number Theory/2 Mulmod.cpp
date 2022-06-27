ll mulmod(ll a, ll b, ll mod)
{
    if(b == 0)
        return 0;
    ll res = mulmod(a, b>>1, mod);
    res = (res<<1)%mod;
    if(b&1)
        return (res+a)%mod;
    else
        return res;
}

ll mulmod2(ll a, ll b, ll mod)
{
    ll ret = 0;

    while(b)
    {
        if(b&1)
            ret += a;
        
        a = a*2;
        b /= 2;
    }

    return ret;
}