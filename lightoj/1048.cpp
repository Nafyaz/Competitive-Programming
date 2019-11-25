#include<bits/stdc++.h>
using namespace std;

#define N 1010
int primes[N], flag[N];

void sieve()
{
    int i, j, val = sqrt(N) + 1;
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
    int total = 0;
    for(i = 2; i < N; i++)
    {
        if(!flag[i])
            primes[total++] = i;
    }
}

int main()
{
    sieve();
    int n, i, j;
    scanf("%d", &n);

    vector <int> v;
    for(i = 0; primes[i] <= n; i++)
    {
        for(j = primes[i]; j <= n; j *= primes[i])
            v.push_back(j);
    }

    printf("%d\n", v.size());
    for(i = 0; i < v.size(); i++)
        printf("%d ", v[i]);
}
