#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, i, maxr = 0, r = 0;
    scanf("%d", &n);
    int a[n];

    FORAB(i, 0, n)
    {
        scanf("%d", &a[i]);
        if(a[i] == 1)
            r++;
        else if(a[i] == 0)
            r = 0;
        if(r > maxr)
            maxr = r;
    }
    FORAB(i, 0, n)
    {
        if(a[i] == 0)
            break;
        r++;
        if(r > maxr)
            maxr = r;
    }
    printf("%d", maxr);
}
