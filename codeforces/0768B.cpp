#include<bits/stdc++.h>
using namespace std;

long long func(long long n, long long l, long long r)
{

    long long length = (1LL << (long long)(log2(n) + 1)) - 1, return_value;
    if(length < l || r == 0)
    {
//        printf("%lld %lld %lld 0\n", n, l, r);
        return 0;
    }
    if(n == 1 && l == 1 && r == 1)
    {
//        printf("%lld %lld %lld 1\n", n, l, r);
        return 1;
    }

    length = (1LL << (long long)(log2(n/2) + 1)) - 1;
    long long mid = l <= (length+1) && r >= (length + 1)? (n&1) : 0;

    return_value = func(n/2, l, min(r, length)) + mid + func(n/2, max(1LL, l - length - 1), max(0LL, r - length - 1));
//    printf("%lld %lld %lld %lld\n", n, l, r, return_value);

    return return_value;
}

int main()
{
    long long n, l, r;
    scanf("%lld %lld %lld", &n, &l, &r);
    printf("%lld", func(n, l, r));
}
