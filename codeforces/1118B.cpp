#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, k, n, o, e, c = 0, candy_number;
    scanf("%d", &n);
    int a[n];

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(i = 0; i < n; i++)
    {
        o = 0;
        e = 0;
        k = 0;
        for(j = 0; j < n; j++)//j is candy number
        {
            if(j == i)
            {
                k++;
                continue;
            }

            if( (j-k) % 2 == 1)
                e += a[j];
            else
                o += a[j];
        }
        if(o == e)
            c++;
    }
    printf("%d\n", c);
}
