ll trie[6800009][2], len[6800009];
ll id;

void Add(ll x)
{
    ll r = 0;

    for(ll i = 34; i >= 0; i--)
    {
        ll bit = ((x & (1LL << i)) >> i);

        if(trie[r][bit] == 0)
            trie[r][bit] = ++id;

        r = trie[r][bit];
        len[r]++;
    }
}

void Erase(ll x)
{
    ll r = 0;

    for(ll i = 34; i >= 0; i--)
    {
        ll bit = ((x & (1LL << i)) >> i);

        r = trie[r][bit];
        len[r]--;
    }
}

int main()
{
    ll q, x;
    string s;

    Add(0); //Majhemoddhe 0 dhukano lagbe

    cin >> q;

    while(q--)
    {
        cin >> s >> x;

        if(s == "+")
            Add(x);
        else if(s == "-")
            Erase(x);
    }
}
