#include<bits/stdc++.h>
using namespace std;
#define sz 1700009
#define ll long long

ll k;
ll trie[sz][2], len[sz];
ll id = 0;

void Add(ll x)
{
    ll i, r = 0;

    for(i = 22; i >= 0; i--)
    {
        ll bit = ((x & (1<<i)) >> i);

        if(trie[r][bit] == 0)
            trie[r][bit] = ++id;

        r = trie[r][bit];
        len[r]++;
    }
}

ll func(ll x)
{
    ll i, r = 0, ret = 0;

    for(i = 22; i >= 0; i--)
    {
        ll bitx = ((x & (1<<i)) >> i);
        ll bitk = ((k & (1<<i)) >> i);

        if(bitx == 0 && bitk == 0)
        {
            if(trie[r][0] == 0)
                return ret;
            r = trie[r][0];
        }
        else if(bitx == 1 && bitk == 0)
        {
            if(trie[r][1] == 0)
                return ret;
            r = trie[r][1];
        }
        else if(bitx == 0 && bitk == 1)
        {
            if(trie[r][0] != 0)
                ret += len[trie[r][0]];

            if(trie[r][1] == 0)
                return ret;
            r = trie[r][1];
        }
        else
        {
            if(trie[r][1] != 0)
                ret += len[trie[r][1]];

            if(trie[r][0] == 0)
                return ret;
            r = trie[r][0];
        }
    }

    return ret;
}

int main()
{
    ll t, i, n, a, cnt, prexor;

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        memset(trie, 0, sizeof trie);
        memset(len, 0, sizeof len);
        id = 0;
        prexor = 0;

        cnt = 0;
        Add(0);
        for(i = 1; i <= n; i++)
        {
            cin >> a;
            prexor ^= a;

            cnt += func(prexor);
            Add(prexor);
        }

        cout << cnt << "\n";
    }
}
