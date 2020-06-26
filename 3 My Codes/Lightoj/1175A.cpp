#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k, ans;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        scanf("%lld %lld", &n, &k);
        while(n)
        {
            ans += n%k;
            n /= k;
            if(n)
                ans++;
        }
        printf("%lld\n", ans);
    }
}
