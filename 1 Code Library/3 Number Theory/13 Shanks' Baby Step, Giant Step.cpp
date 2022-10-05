LL bigmod(LL b, LL p, LL m) {}

LL babyStepGiantStep(LL a, LL b, LL p)
{
    LL i, j, c, sq = sqrt(p);
    map<LL, LL> babyTable;

    for(j = 0, c = 1; j <= sq; j++, c = (c*a)%p)
        babyTable[c] = j;

    LL giant = bigmod(a, sq*(p-2), p);

    for(i = 0, c = 1; i <= sq; i++, c = (c*giant)%p)
    {
        if(babyTable.find((c*b)%p) != babyTable.end())
            return i*sq+babyTable[(c*b)%p];
    }

    return -1;
}
