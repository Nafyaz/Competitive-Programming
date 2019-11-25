//tutorial dekhar por eita lekhsi
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    char c;
    for(i = 0; i < n; i++)
    {
        getchar();
        for(j = 0; j < m; j++)
        {
            scanf("%c", &c);
            if(c == '-')
                printf("%c", c);
            else
                ((i%2) + (j%2))%2 ? printf("W") : printf("B");
        }
        printf("\n");
    }
}
