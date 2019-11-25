#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

long long gcd(long long a, long long b)
{
    long long temp;
    while(b)
    {
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int main()
{
    long long n, i, x, y, hits, lcm, a, b;
    scanf("%I64d %I64d %I64d", &n, &x, &y);
    lcm = x * y / gcd(x, y);

    FORAB(i, 0, n)
    {
        scanf("%I64d", &hits);
        while(1)
        {
            if(x)
        }
    }
}
