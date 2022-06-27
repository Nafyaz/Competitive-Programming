// Easy BruteForce
bool isPrime(ll n)
{
    ll i;
    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
            return 0;
    }

    return 1;
}

// Fermat's Primality Test, vulnerable to Charmichael numbers
bool isPrime2(ll n)
{
    vector<ll> checkerPrimes = {2, 3, 5, 7};
    if(binary_search(checkerPrimes.begin(), checkerPrimes.end(), n) == 1)
        return 1;

    vector<ll> carmichael = {561,1105,1729,2465,2821,6601,8911,10585,15841,
					29341,41041,46657,52633,62745,63973,75361,101101,
					115921,126217,162401,172081,188461,252601,278545,
					294409,314821,334153,340561,399001,410041,449065,
					488881,512461};

    if(binary_search(carmichael.begin(), carmichael.end(), n) == 1)
        return 0;

    for(auto cp : checkerPrimes)
    {
        if(bigmod(cp, n, n) != cp%n)
            return 0;
    }

    return 1;
}