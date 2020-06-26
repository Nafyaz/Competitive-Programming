#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, caseno = 0, c;
    long long n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        if(n&1)
        {
            printf("Case %d: Impossible\n", ++caseno);
            continue;
        }
        c = 0;
        while(!(n&1))
        {
            n = n >> 1;
            c++;
        }
        printf("Case %d: %lld %lld\n", ++caseno, n, 1LL<<c);
    }
}
