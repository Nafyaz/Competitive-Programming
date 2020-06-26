#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long x, y, z;
    scanf("%lld %lld %lld", &x, &y, &z);
    long long a, b;
    a = x/z;
    b = y/z;

    printf("%lld ", (x+y)/z);

    if(a + b == (x+y)/z)
    {
        printf("0");
    }
    else
    {
        if(x - a*z > y - b*z)
            printf("%lld", (a+1)*z - x);
        else
            printf("%lld", (b+1)*z - y);
    }
}
