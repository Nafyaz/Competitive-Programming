#include<bits/stdc++.h>
using namespace std;

long long make_palindrome(long long n)
{
    long long temp = n, x = 0;
    int digit = floor(log10(n)) + 1;
    n =  n * pow(10, digit);
    while(temp)
    {
        x = 10*x + temp%10;
        temp /= 10;
    }
    return n+x;
}

int main()
{
    long long i, k, p, ans = 0;
    scanf("%lld %lld", &k, &p);
    for(i = 1; i <= k; i++)
        ans = (ans + make_palindrome(i)) % p;

    printf("%lld", ans);
}
