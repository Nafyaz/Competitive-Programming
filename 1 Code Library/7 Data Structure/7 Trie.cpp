// Sometimes you need to use Add(0) at first

LL trie[MAXN][2], len[MAXN];
LL id;

void Add(LL x)
{
    LL r = 0;

    for(LL i = 34; i >= 0; i--)
    {
        LL bit = ((x & (1LL << i)) >> i);

        if(trie[r][bit] == 0)
            trie[r][bit] = ++id;

        r = trie[r][bit];
        len[r]++;
    }
}

void Erase(LL x)
{
    LL r = 0;

    for(LL i = 34; i >= 0; i--)
    {
        LL bit = ((x & (1LL << i)) >> i);

        r = trie[r][bit];
        len[r]--;
    }
}
