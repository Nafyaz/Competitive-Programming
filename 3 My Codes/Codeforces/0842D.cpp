#include<bits/stdc++.h>
using namespace std;

int trie[300009][2], len[300009];
int id;

void Add(int a)
{
    int i, r = 0;

    for(i = 20; i >= 0; i--)
    {
        int bit = ((a & (1<<i)) >> i);

        if(trie[r][bit] == 0)
            trie[r][bit] = ++id;

        r = trie[r][bit];
        len[r]++;
    }
}

int mex(int curr)
{
    int i, r = 0, ret = 0;

    for(i = 20; i >= 0; i--)
    {
        int bit = ((curr & (1<<i)) >> i);

        if(bit == 1 && trie[r][bit] != 0 && len[trie[r][bit]] == (1<<i))
    }
}

int main()
{
    int i, n, m, a, x, curr;
    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        Add(a);
    }

    curr = 0;
    while(m--)
    {
        cin >> x;
        curr ^= x;

        cout << mex(curr) << "\n";
    }
}
