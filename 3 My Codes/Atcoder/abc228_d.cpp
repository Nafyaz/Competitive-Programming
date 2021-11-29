#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1048576

ll a[N];
ll p[N];

ll Find(ll h)
{
    if(p[h] == h)
        return h;
    return p[h] = Find(p[h]);
}

int main()
{
    ll q, t, x, h, hp, i;

    for(i = 0; i < N; i++)
    {
        a[i] = -1;
        p[i] = i;
    }

    cin >> q;

    while(q--)
    {
        cin >> t >> x;

        h = x % N;

        if(t == 1)
        {
            hp = Find(h);
            a[hp] = x;
            p[hp] = Find((hp+1)%N);
        }
        else
            cout << a[h] << "\n";
    }
}
