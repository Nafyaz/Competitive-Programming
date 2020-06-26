#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, a, b, c, d;
    scanf("%lld %lld %lld %lld %lld", &n, &a, &b, &c, &d);
    long long x = max({a+b, a+c, b+d, c+d}) - min({a+b, a+c, b+d, c+d});

    printf("%lld", n*max(0LL, n-x));
}
