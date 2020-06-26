#include<bits/stdc++.h>
using namespace std;


#define N 1000
#define P 1000

bool flag[N+5];
int prime[P+5];

int sieve()
{
    int i, j, sq = sqrt(N) + 1;

    for(i = 2; i <= N; i++)
        flag[i] = 1;
    for(i = 2; i <= sq; i++)
    {
        if(flag[i])
        {
            for(j = i; j*i <= N; j++)
            {
                flag[i*j] = 0;
            }
        }
    }
    int total = 0;
    for(i = 2; i <= N; i++)
    {
        if(flag[i])
            prime[total++] = i;
    }
    return total;
}
int main()
{
    printf("Total number of primes: %d", total);
}
