#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);

    if(n%2 == 0)
    {
        printf("NO");
        return 0;
    }

    int i, a[2*n];

    for(i = 0; i < n; i++)
    {
        if(i%2 == 0)
        {
            a[i] = 2*i + 1;
            a[i+n] = 2*i + 2;
        }

        else
        {
            a[i+n] = 2*i + 1;
            a[i] = 2*i + 2;
        }
    }

    printf("YES\n");
    for(i = 0; i < 2*n; i++)
        printf("%d ", a[i]);
}
