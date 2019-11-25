#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, ans = 0;
    scanf("%d %d", &n, &m);

    while(m > n)
    {
        if(m & 1)
            m++;
        else
            m = m >> 1;
        ans++;
    }
    if(m < n)
        ans += n - m;

    printf("%d", ans);
}
