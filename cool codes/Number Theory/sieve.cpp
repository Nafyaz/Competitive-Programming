#include<bits/stdc++.h>
using namespace std;
#define N 1000
bool flag[N + 5];
int total, primes[N + 5];
int sieve()
{
    int i, j, val = sqrt(N) + 1;

    flag[2] = 1;
    for(i = 3; i <= N; i += 2)
        flag[i] = 1;

    for(i = 3; i < val; i++)
    {
        if(flag[i])
        {
            for(j = i*i; j <= N; j += 2*i)
                flag[j] = 0;
        }
    }

    for(i = 2; i <= N; i++)
    {
        if(flag[i])
            primes[total++] = i;
    }
}
int main()
{
    int i;
    sieve();
    printf("%d\n", total);
    for(i = 0; i < total; i++)
        printf("%d %d\n", i+1, primes[i]);
}
