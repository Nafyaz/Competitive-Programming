#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k, x;
    scanf("%lld %lld", &n, &k);

    long long l = 1, h = n, m;
    while(1)
    {
        m = (l+h)/2;
        x = m*(m+1)/2;
        x = x - (n-m);
        if(x > k)
            h = m - 1;
        else if(x < k)
            l = m + 1;
        else
            break;
    }

    printf("%lld", n - m);
}
