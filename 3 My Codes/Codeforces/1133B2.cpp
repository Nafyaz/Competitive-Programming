#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, k, i, c, total = 0;

    scanf("%d %d", &n, &k);
    int a[k] = {0};
    FORAB(i, 0, n)
    {
        scanf("%d", &c);
        if(c%k <= k/2)
            a[c%k] ++;
        else
            a[c%k - k/2]++;
    }

    FORAB(i, 0, k)
    {
        total += a[i]&(~1);
        printf("%d %d\n", a[i],  a[i]&(~1));
    }
    printf("%d", total);
}
