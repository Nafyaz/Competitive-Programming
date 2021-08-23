#include<bits/stdc++.h>
using namespace std;

int trie[30000007][2];
bool flag[300005];
int id;

void Add(int a)
{
    int i, r = 0;

    for(i = 19; i >= 0; i--)
    {
        int bit = ((a & (1<<i)) >> i);

        if(trie[r][bit] == 0)
            trie[r][bit] = ++id;

        r = trie[r][bit];
    }
}

int mex(int curr)
{
    int i, r = 0, ret = 0;

    for(i = 19; i >= 0; i--)
    {
        int bit = ((curr & (1<<i)) >> i);

        if(trie[r][bit] != 0)
        {
            r = trie[r][bit];
        }
        else
        {
            ret |= (1<<i);
            r = trie[r][bit^1];
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int i, n, m, a, x, curr;
    cin >> n >> m;

    for(i = 0; i < n; i++)
    {
        cin >> a;
        flag[a] = 1;
    }

    for(i = 0; i < (1 << 19); i++)
    {
        if(i >= 300005 || !flag[i])
            Add(i);
    }

    curr = 0;
    while(m--)
    {
        cin >> x;
        curr ^= x;

        cout << mex(curr) << "\n";
    }
}

