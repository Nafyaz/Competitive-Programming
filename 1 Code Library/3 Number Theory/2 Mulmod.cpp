LL mulmod(LL a, LL b, LL mod)
{
    if(b == 0)
        return 0;
    LL res = mulmod(a, b>>1, mod);
    res = (res<<1)%mod;
    if(b&1)
        return (res+a)%mod;
    else
        return res;
}

LL mulmod2(LL a, LL b, LL mod)
{
    LL ret = 0;

    while(b)
    {
        if(b&1)
            ret += a;
        
        a = a*2;
        b /= 2;
    }

    return ret;
}