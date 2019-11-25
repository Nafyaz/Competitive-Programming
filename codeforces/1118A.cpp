#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    long long int n, a, b;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%I64d %I64d %I64d", &n, &a, &b);
        if(b < 2*a)
            printf("%I64d\n", n/2*b + a*(n%2));

        else
            printf("%I64d\n", a*n);
    }
}
