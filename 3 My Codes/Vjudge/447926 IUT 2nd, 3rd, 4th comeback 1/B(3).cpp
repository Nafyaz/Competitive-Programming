#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll p[16009];

ll getones(ll i, ll j)
{
    if(j-i+1 == 64)
        return -1;
    else
        return ((1LL << (j-i+1)) - 1) << i;
}

void update0(ll a, ll b)
{
    ll st = a/64, ed = b/64;
    ll i = a%64, j = b%64;

    if(st == ed)
    {
        p[st] &= ~getones(i, j);
        return;
    }

    p[st] &= ~getones(i, 63);
    for(int x = st+1; x < ed; x++)
        p[x] = 0;
    p[ed] &= ~getones(0, j);
}

void update1(ll a, ll b)
{
    ll st = a/64, ed = b/64;
    ll i = a%64, j = b%64;

    if(st == ed)
    {
        p[st] |= getones(i, j);
        return;
    }

    p[st] |= getones(i, 63);
    for(int x = st+1; x < ed; x++)
        p[x] = -1;
    p[ed] |= getones(0, j);
}

void inverse(ll a, ll b)
{
    ll st = a/64, ed = b/64;
    ll i = a%64, j = b%64;

    if(st == ed)
    {
        p[st] ^= getones(i, j);
        return;
    }

    p[st] ^= getones(i, 63);
    for(int x = st+1; x < ed; x++)
        p[x] = ~p[x];
    p[ed] ^= getones(0, j);
}

ll query(ll a, ll b)
{
    ll st = a/64, ed = b/64;
    ll i = a%64, j = b%64;

    ll ret = 0;
    if(st == ed)
    {
        ret = ret + __builtin_popcountll(p[st] & getones(i, j));
        return ret;
    }

    ret += __builtin_popcountll(p[st] & getones(i, 63));
    for(int x = st+1; x < ed; x++)
        ret += __builtin_popcountll(p[x]);
    ret += __builtin_popcountll(p[ed] & getones(0, j));

    return ret;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    ll t, caseno = 0, N, M, T, Q, queryno, a, b, i;
    string pirates, type;

    cin >> t;

    while(t--)
    {
        memset(p, 0, sizeof p);
        cin >> M;

        N = 0;

        while(M--)
        {
            cin >> T >> pirates;

            while(T--)
            {
                for(i = 0; i < pirates.size(); i++)
                {
                    p[N/64] |= ((ll)(pirates[i] - '0')) << (N%64);
                    N++;
                }
            }
        }

        cin >> Q;

        cout << "Case " << ++caseno << ":\n";

        queryno = 0;

        while(Q--)
        {
//            for(i = 0; i < 18; i++)
//                cout << ((p[i/64] & (1LL << i%64)) >> (i%64)) << " ";
//            cout << "\n";

            cin >> type >> a >> b;

            if(type == "F")
                update1(a, b);
            else if(type == "E")
                update0(a, b);
            else if(type == "I")
                inverse(a, b);
            else
                cout << "Q" << ++queryno << ": " << query(a, b) << "\n";
        }
    }
}
