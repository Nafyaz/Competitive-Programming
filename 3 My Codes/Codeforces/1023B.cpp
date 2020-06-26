#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    scanf("%I64d %I64d", &n, &k);

    long long temp = n - k/2;
    temp < 0? temp = 0 : temp = temp;
    k%2 == 0 ? printf("%I64d", min(k/2 - 1, temp)) : printf("%I64d", min(k/2, temp));
}
