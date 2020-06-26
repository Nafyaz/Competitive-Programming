#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j;
    scanf("%d", &n);

    int a[n];

    for(i = 0; i < n; i++)
        a[i] = 1;

    int val = sqrt(n + 1) + 1;
    for(i = 2; i < val; i++)
    {
        if(a[i-2] == 1)
        {
            for(j = 2*i; j <= n+1; j += i)
                a[j-2] = 2;
        }
    }

    n >= 3? printf("2\n") : printf("1\n");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
}
