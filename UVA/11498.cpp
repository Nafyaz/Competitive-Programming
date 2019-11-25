#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k, i, j, n, m;
    while(scanf("%d", &k) == 1)
    {
        scanf("%d %d", &n, &m);

        while(k--)
        {
            scanf("%d %d", &i, &j);
            if(i == n || j == m)
                printf("divisa\n");
            else if (i > n)
            {
                j > m? printf("NE\n") : printf("SE\n");
            }
            else
            {
                j > m? printf("NO\n") : printf("SO\n");
            }
        }
    }
}
