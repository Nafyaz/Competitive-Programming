#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b, c;
    scanf("%lld", &a);
    if(a == 1 || a == 2)
    {
        printf("-1");
        return 0;
    }
    if(a&1)
    {
        c = (a*a + 1) >> 1;
        b = c - 1;
        printf("%lld %lld", b, c);
    }
    else
    {
        a = a >> 1;
        b = a*a - 1;
        c = a*a + 1;
        printf("%lld %lld", b, c);
    }
}
