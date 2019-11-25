#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long lena, lenb, la, lb, i, j, ans;

    scanf("%lld", &lena);
    long long a[lena];
    for(i = 0; i < lena; i++)
        scanf("%lld", &a[i]);

    scanf("%lld", &lenb);
    long long b[lenb];
    for(i = 0; i < lenb; i++)
        scanf("%lld", &b[i]);

    ans = la = lb = 0;
    while(la < lena && lb < lenb)
    {
        if(a[la] == b[lb])
        {
            ans++;
            la++;
            lb++;
        }
        else if(a[la] > b[lb])
        {
            b[lb + 1] += b[lb];
            lb++;
        }
        else if(a[la] < b[lb])
        {
            a[la + 1] += a[la];
            la++;
        }
        if(la == lena - 1 && lb == lenb - 1 && a[la] != b[lb])
        {
            printf("-1");
            return 0;
        }
    }
    if(la == lena && lb == lenb)
        printf("%lld", ans);
    else
        printf("-1");
}
