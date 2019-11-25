#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, c, i;
    scanf("%d %d", &n, &c);
    int a[n];

    FORAB(i, 0, n)
        scanf("%d", &a[i]);

    int maxdiff = 0, maxi = -1;
    FORAB(i, 0, n - 1)
    {
        if(a[i] - a[i + 1] > maxdiff)
        {
            maxdiff = a[i] - a[i + 1];
            maxi = i;
        }
    }
    maxdiff - c <= 0? printf("0") : printf("%d", maxdiff - c);
}
