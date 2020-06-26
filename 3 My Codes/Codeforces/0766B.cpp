#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, i, j, k;
    scanf("%d", &n);
    int a[n];
    FORAB(i, 0, n)
        scanf("%d", &a[i]);

    sort(a, a+n);

    FORAB(i, 0, n-2)
    {
        FORAB(j, i+1, n-1)
        {
            if(a[i] + a[j] > a[j + 1])
            {
                printf("YES\n");
                    return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
