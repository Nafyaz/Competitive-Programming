#include<bits/stdc++.h>
using namespace std;
long long nC2(long long x)
{
    return x*(x-1) / 2;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    long long mn = (n%m) * nC2(n/m + 1) + (m - n%m) * nC2(n/m);
    long long mx = nC2(n - m + 1);
    printf("%lld %lld", mn, mx);

}
