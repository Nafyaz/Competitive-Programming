#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, q, i, j, mx = -1, mi = -1, a, b;
    scanf("%lld %lld", &n, &q);
    long long m;

    long long ar[n];
    deque <long long> d;
    vector <pair<long long, long long> > v;

    for(i = 0; i < n; i++)
    {
        scanf("%lld", &ar[i]);
        d.push_back(ar[i]);
    }

    for(i = 0; i < n-1; i++)
    {
        a = d.front();
        d.pop_front();
        b = d.front();
        d.pop_front();

        v.push_back({a, b});

        if(a > b)
        {
            d.push_front(a);
            d.push_back(b);
        }
        else
        {
            d.push_front(b);
            d.push_back(a);
        }
    }

    for(i = 0; i < q; i++)
    {
        scanf("%lld", &m);
        if(m < n)
            printf("%lld %lld\n", v[m - 1].first, v[m - 1].second);
        else
            printf("%lld %lld\n", d[0], d[((m - n) % (n-1)) + 1]);
    }

}
