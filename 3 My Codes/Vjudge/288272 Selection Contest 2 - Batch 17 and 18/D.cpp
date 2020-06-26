#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

char p[110][110];

int main()
{
    int t, i, j;
    scanf("%d", &t);
    int r1, c1, r2, c2;
    char color;
    while(t--)
    {
        int r, c, x, k;
        scanf("%d %d %d", &r, &c, &x);

        FORAB(i, 1, r + 1)
        {
            FORAB(j, 1, c + 1)
                p[i][j] = '.';
        }

        FORAB(k, 0, x)
        {
            scanf("%d %d %d %d %c", &r1, &c1, &r2, &c2, &color);
            FORAB(i, r1, r2 + 1)
            {
                FORAB(j, c1, c2 + 1)
                    p[i][j] = color;
            }
        }

        FORAB(i, 1, r + 1)
        {
            FORAB(j, 1, c + 1)
                printf("%c", p[i][j]);
            printf("\n");
        }
    }
}
