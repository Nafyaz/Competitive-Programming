#include<bits/stdc++.h>
using namespace std;
#define N 1000010
bool flag[N];
long long primes[N];
long long total;
long long sieve()
{
    int i, j, val = sqrt(N) + 1, total = 0;
    flag[0] = flag[1] = 1;
    for(i = 4; i < N; i += 2)
        flag[i] = 1;
    for(i = 3; i < val; i++)
    {
        if(!flag[i])
        {
            for(j = i*i; j < N; j += 2*i)
                flag[j] = 1;
        }
    }
    for(i = 2; i < N; i++)
    {
        if(!flag[i])
            primes[total++] = i;
    }
    return total;
}
long long nod(long long n)
{
    long long i, c, sum = 1, val = sqrt(n) + 1;
    for(i = 0; primes[i] < val && i < total; i++)
    {
        for(c = 0; n%primes[i] == 0; c++)
            n /= primes[i];
        sum *= (c + 1);
    }
    if(n > 1)
        sum *= 2;
    return sum;
}
int main()
{
    long long T, caseno = 0, i, j, val;
    long long n;
    total = sieve();
    scanf("%I64d", &T);
    while(T--)
    {
        scanf("%I64d", &n);
        if(n == 1)
            printf("Case %I64d: 0\n", ++caseno);
        else
            printf("Case %I64d: %I64d\n", ++caseno, nod(n) - 1);
    }
}
