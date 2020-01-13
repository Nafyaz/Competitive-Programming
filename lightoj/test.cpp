#include<stdio.h>
int main()
{
    char check[3];
    char card[5][3];
    int i,j,k;

    scanf("%s",check);
    printf("%s\n", check);

    for(i=0; i<5; i++)
        scanf("%s", card[i]);

    for(i = 0; i < 5; i++)
        printf("%s ", card[i]);

    for(j=0; j<10; j=j++)
    {
        if(check[0]==card[j]||check[1]==card[j])
        {
            printf("YES");
            break;
        }
        else
            printf("NO");
    }
    return 0;
}
