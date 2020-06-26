#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r, c, i, j;
    scanf("%d %d", &r, &c);

    char s[r][c+1];
    for(i = 0; i < r; i++)
        scanf("%s", s[i]);

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(s[i][j] == 'W')
            {
                if(i != 0 && s[i-1][j] == 'S')
                {
                    printf("No");
                    return 0;
                }
                if(i != r-1 && s[i+1][j] == 'S')
                {
                    printf("No");
                    return 0;
                }
                if(j != c-1 && s[i][j+1] == 'S')
                {
                    printf("No");
                    return 0;
                }
                if(j != 0 && s[i][j-1] == 'S')

                {
                    printf("No");
                    return 0;
                }
            }
        }
    }

    printf("Yes\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(s[i][j] == '.')
                printf("D");
            else
                printf("%c", s[i][j]);
        }
        printf("\n");
    }
}
