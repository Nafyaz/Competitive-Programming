#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    scanf("%I64d", &n);
    n ? ((n + 1) & 1)? printf("%I64d", n + 1) : printf("%I64d", (n + 1) >> 1 ) :printf("0");
}
