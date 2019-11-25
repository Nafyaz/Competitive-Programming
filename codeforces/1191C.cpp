#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i, n, m, k, page;
    scanf("%lld %lld %lld", &n, &m, &k);
    long long p[m];

    for(i = 0; i < m; i++)
        scanf("%lld", &p[i]);

    long long diff, ans = 0;
    i = 0;
    for(page = k; i < m;)
    {
        diff = i;
        while(i < m && p[i] <= page)
            i++;

        diff = i - diff;
        page += diff;

        if(diff)
            ans ++;

        if(p[i] > page)
             page = page + ((p[i] - page - 1)/k + 1)*k;
    }
    printf("%lld", ans);
}
