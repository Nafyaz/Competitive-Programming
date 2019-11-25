#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    long long int n, ans = 0, i;
    scanf("%I64d", &n);

    for(i = 2; i < n; i++)
        ans = ans + i * (i + 1);
    printf("%I64d", ans);
}
