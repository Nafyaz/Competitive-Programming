//vai er code dekhar por eita lekhsi
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, i, s, total = 0, mins;
    scanf("%lld %lld", &n, &s);
    long long a[n];
    for(i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        total += a[i];
        if(i == 0)
            mins = a[i];
        else
            mins = min(a[i], mins);
    }

    if(total < s)
    {
        printf("-1");
        return 0;
    }

    printf("%lld", min(mins, (total - s)/n));
}
