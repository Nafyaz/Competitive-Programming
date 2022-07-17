#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bitset<MAXN> Add(bitset<MAXN> a, bitset<MAXN> b)
{
    bitset<MAXN> carry;
    while(b != bitset<MAXN>(0))
    {
        carry = a&b;
        a = a^b;
        b = carry << 1;
    }

    return a;
}

bitset<MAXN> Sub(bitset<MAXN> a, bitset<MAXN> b)
{
    b = ~b;
    b = Add(b, bitset<MAXN>(1));

    return Add(a, b);
}