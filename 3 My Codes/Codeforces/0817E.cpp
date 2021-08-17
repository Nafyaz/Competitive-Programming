#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll trie[3400009][2], len[3400009];
ll id;

void Add(ll p)
{
    ll i, r = 0;

    for(i = 34; i >= 0; i--)
    {
        ll bit = ((p & (1LL << i)) >> i);

        if(trie[r][bit] == 0)
            trie[r][bit] = ++id;

        r = trie[r][bit];
        len[r]++;
    }
}

void Remove(ll p)
{
    ll i, r = 0;

    for(i = 34; i >= 0; i--)
    {
        ll bit = ((p & (1LL << i)) >> i);

        r = trie[r][bit];
        len[r]--;
    }
}

ll Respect(ll p, ll l)
{
    ll i, r = 0, ret = 0;

    for(i = 34; i >= 0; i--)
    {
        ll bitp = ((p & (1LL << i)) >> i);
        ll bitl = ((l & (1LL << i)) >> i);

        if(bitp == 0 && bitl == 0)
        {
            if(trie[r][0] == 0 || len[trie[r][0]] == 0)
                return ret;
            r = trie[r][0];
        }
        else if(bitp == 1 && bitl == 0)
        {
            if(trie[r][1] == 0 || len[trie[r][1]] == 0)
                return ret;
            r = trie[r][1];
        }
        else if(bitp == 0 && bitl == 1)
        {
            if(trie[r][0] != 0)
                ret += len[trie[r][0]];

            if(trie[r][1] == 0 || len[trie[r][1]] == 0)
                return ret;
            r = trie[r][1];
        }
        else
        {
            if(trie[r][1] != 0)
                ret += len[trie[r][1]];

            if(trie[r][0] == 0 || len[trie[r][0]] == 0)
                return ret;
            r = trie[r][0];
        }
    }

    return ret;
}

int main()
{
    ll q, type, p, l;

    cin >> q;

    while(q--)
    {
        cin >> type >> p;

        if(type == 1)
            Add(p);
        else if(type == 2)
            Remove(p);
        else
        {
            cin >> l;

            cout << Respect(p, l) << "\n";
        }
    }
}
/*
7
1 1
1 2
1 3
1 4
3 5 3
2 4
3 5 3
*/
