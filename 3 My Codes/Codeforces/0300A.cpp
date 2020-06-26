#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, zero = 0;
    scanf("%d", &n);
    int a[n];
    int pos[n], neg[n], j = 0, k = 0;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);

        if(a[i] < 0)
        {
            neg[k] = a[i];
            k++;
        }
        else if(a[i] == 0)
            zero++;

        else
        {
            pos[j] = a[i];
            j++;
        }
    }
    printf("1 %d\n", neg[0]);

    if(j%2 == 0 || j == 1)
    {
        printf("%d ", j + k - 1);
        for(i = 1; i < k; i++)
            printf("%d ", neg[i]);
        for(i = 0; i < j; i++)
            printf("%d ", pos[i]);
        printf("\n");

        printf("%d ", zero);
        for(i = 0; i < zero; i++)
            printf("0 ");
        printf("\n");
    }


    else
    {
        printf("%d ", j + k - 1);
        for(i = 1; i < k; i++)
            printf("%d ", neg[i]);
        for(i = 1; i < j; i++)
            printf("%d ", pos[i]);
        printf("\n");

        printf("%d ", zero + 1);
        for(i = 0; i < zero; i++)
            printf("0 ");
        printf("%d\n", pos[0]);
    }
}
