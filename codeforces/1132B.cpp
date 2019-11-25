#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    long long int n, i, m, j, q, sum = 0;
    scanf("%I64d", &n);

    int a[n];

    FORAB(i, 0, n)
    {
        scanf("%I64d", &a[i]);
        sum += a[i];
    }
    sort(a, a+n);

    scanf("%I64d", &m);

    FORAB(i, 0, m)
    {
        scanf("%I64d", &q);
        printf("%I64d\n", sum - a[n - q]);
    }


}
