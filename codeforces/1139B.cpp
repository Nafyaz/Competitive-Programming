#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    long long int n, i;
    scanf("%I64d", &n);
    long long int a[n];

    FORAB(i, 0, n)
        scanf("%I64d", &a[i]);

    long long int sum = a[n - 1];
    long long int temp = a[n - 1];
    for(i = n - 2; i >= 0; i--)
    {
        temp = min(max(temp - 1, 0LL), a[i]);
        sum += temp;
    }
    printf("%I64d", sum);
}
