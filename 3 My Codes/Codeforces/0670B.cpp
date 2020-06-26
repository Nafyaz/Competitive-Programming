#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for( i = a; i <= b; i++)

int main()
{
    long long n, k, i;
    scanf("%I64d %I64d", &n, &k);
    int a;

    i = 1;
    while(i*(i + 1) / 2 < k)
    {
        i++;
    }
    k = k - (i - 1) * i / 2;

    FORAB(i, 1, n)
    {
        scanf("%d", &a);
        if(i == k)
            printf("%d", a);
    }
}
