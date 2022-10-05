/*
We need actual value assuming answer fits in long long
    1.  O(r): Multiply by (n-i) and divide by i, in each step. C(n, r) = C(n-1, r-1)*n/r

Prime mod M
    2.  O(n): Precalculate factorial and inverse factorial array.
        O(1): Answer each query from these arrays
    3.  O(M): Use Lucas Theorem

Non-prime mod M
    4.  O(n*n): Use Pascal's Triangle
    5.  O(M): Use Chinese Remainder Theorem
*/

LL fact[2000006];
LL inv[2000006];
LL dp[500][500];

LL getFact(LL n, LL mod);
LL bigmod(LL a, LL p, LL mod);
LL invmod(LL a, LL mod);

LL nCr1(LL n, LL r)
{
    if(n < r)
        return 0;

    r = min(r, n-r);

    if(r == 0)
        return 1;

    return n * nCr1(n-1, r-1) / r;
}

LL nCr2(LL n, LL r, LL mod)
{
    if(n < r)
        return 0;

    LL ret = getFact(n, mod);
    ret = (ret * invmod(getFact(r, mod), mod)) % mod;
    ret = (ret * invmod(getFact(n-r, mod), mod)) % mod;
    return ret;
}

LL nCr3(LL n, LL r, LL mod)
{
    if(n < r)
        return 0;

    LL ret = 1;
    while(r)
    {
        ret = (ret * nCr2(n%mod, r%mod))%mod;
        n /= mod;
        r /= mod;
    }

    return ret;
}

LL nCr4(LL n, LL r, LL mod)
{
    if(n < r)
        return 0;

    if(dp[n][r] != 0)
        return dp[n][r];

    if(!r)
        return dp[n][r] = 1;

    return dp[n][r] = (nCr4(n-1, r-1, mod) + nCr4(n-1, r, mod)) % mod;
}

LL nCr5(LL n, LL r, LL mod)
{
    return -1;
}
