#include<bits/stdc++.h>
using namespace std;
#define ll long long

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

ll maxXor(ll x)
{
    ll r = 0, ret = 0;

    for(ll i = 34; i >= 0; i--)
    {
        ret <<= 1LL;
        ll bit = ((x & (1LL << i)) >> i);

        if(trie[r][bit^1LL] == 0 || len[trie[r][bit^1LL]] == 0)
        {
            ret |= bit;
            r = trie[r][bit];
        }
        else
        {
            ret |= (bit^1LL);
            r = trie[r][bit^1LL];
        }
    }

    return ret ^ x;
}

int main()
{
    ll q, x;
    string s;

    Add(0);

    cin >> q;

    while(q--)
    {
        cin >> s >> x;

        if(s == "+")
            Add(x);
        else if(s == "-")
            Erase(x);
        else
            cout << maxXor(x) << "\n";
    }
}
