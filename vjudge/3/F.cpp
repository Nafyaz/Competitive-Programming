#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int i, n, temp = 0, temp2, sum = 0;
    scanf("%d", &n);
    int a[n];

    FORAB(i, 0, n)
    {
        scanf("%d", &a[i]);
        sum += a[i];
        if(temp == 0 && a[i] == 0)
            temp = i - 1;

    }
    if(sum >= n)
    {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for(i = temp; i >= 0; i--)
    {
        while(a[i]--)
        {
            printf("%d %d\n", i + 1, n--);
        }
    }
}
