#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define N 3000009

ull phi[N], ans[N];

void sievephi()
{
    ull i, j;
    for(i = 1; i < N; i++)
        phi[i] = i;
    for(i = 2; i < N; i++)
    {
        if(phi[i] == i)
        {
            for(j = i; j < N; j += i)
                phi[j] = phi[j] / i * (i - 1);
        }
    }
}

void calc()
{
    ull i, j;
    for(i = 1; i < N; i++)
        ans[i]++;

    for(i = 2; i < N; i++)
    {
        for(j = i; j < N; j += i)
            ans[j] += phi[i] * i / 2;
    }

    for(i = 1; i < N; i++)
        ans[i] = ans[i]*i - i;

    for(i = 1; i < N; i++)
        ans[i] += ans[i-1];
}


int main()
{
    sievephi();
    calc();
    ull t, n, caseno = 0;

    scanf("%llu", &t);
    while(t--)
    {
        scanf("%llu", &n);
        printf("Case %llu: %llu\n", ++caseno, ans[n]);
    }
}
