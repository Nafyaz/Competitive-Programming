#include<bits/stdc++.h>
using namespace std;

int main()
{
    int b, k, i;
    scanf("%d %d", &b, &k);
    int a[k];
    int parity = 0;

    for(i = 0; i < k; i++)
        scanf("%d", &a[i]);

    if(b % 2 == 0)
    {
        if(a[k - 1] % 2 == 0)
            printf("even");
        else
            printf("odd");
        return 0;
    }

    for(i = 0; i < k; i++)
        parity = parity + (a[i] % 2);

    if(parity % 2 == 0)
        printf("even");
    else
        printf("odd");

}
