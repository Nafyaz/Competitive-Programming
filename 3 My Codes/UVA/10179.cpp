#include<bits/stdc++.h>
using namespace std;
#define N 100000
bool flag[N];
int primes[N];
int sieve()
{
    int i, j, val = sqrt(N) + 1, total = 0;
    flag[0] = flag[1] = 1;
    for(i = 4; i < N; i += 2)
        flag[i] = 1;
    for(i = 3; i < val; i += 2)
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
int phi(int n)
{
    int i;
}
int main()
{
    sieve();
    int n, i, temp1, temp2, val;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        temp1 = n;
        temp2 = n;
        val = sqrt(n) + 1;

        for(i = 0; primes[i] < val; i++)
        {
            if(temp1%primes[i] == 0)
            {
                temp1 /= primes[i];
                temp1 *= (primes[i] - 1);
                while(temp2 % primes[i] == 0)
                    temp2 /= primes[i];
            }
            //printf("%d %d\n", temp1, temp2);
        }
        if(temp2 > 1)
        {
            temp1 /= temp2;
            temp1 *= (temp2 - 1);
        }
        printf("%d\n", temp1);
    }
}
