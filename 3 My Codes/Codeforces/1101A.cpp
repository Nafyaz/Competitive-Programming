//tutorial dekhe shikhlam

#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    long long q, l, r, d, i;
    scanf("%I64d", &q);

    while(q--)
    {
        scanf("%I64d %I64d %I64d", &l, &r, &d);
        if(d < l)
            printf("%I64d\n", d);
        else
            printf("%I64d\n", (r/d + 1)*d);
    }
}
