#include<bits/stdc++.h>
using namespace std;

map <long long, long long> mp;

long long find(long long x)
{
    if(mp.find(x) == mp.end())
        return x;
    return mp[x] = find(mp[x]);
}

int main()
{
    long long n, t, i, Q;
    long long x, y, l, r, s, q, m;

    scanf("%lld", &t);
    while(t--)
    {
        s = 0;
        mp.clear();
        scanf("%lld %lld", &n, &Q);

        for(i = 0; i < Q; i++)
        {
            scanf("%lld", &q);
            if(q == 1)
            {
                scanf("%lld", &x);
                x = x+s;
                mp[x] = find(x-1);
            }
            else
            {
                scanf("%lld %lld", &l, &r);
                l = l + s;
                r = r + s;

                m = find(r);
                if(m < l)
                    m = 0;
                s = (s + m) % n;
                printf("%lld\n", m);
            }
        }
    }
}
