#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    long long n, a;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%I64d %I64d", &n, &a);
        printf("%I64d\n", min(n, 2*a-1));
    }
}
