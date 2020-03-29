#include<stdio.h>
//int not(a[])
int main()
{
    char x[1];
    int i;
    for(i=1;i<10;i++)
    {
        x[0]='0';
        printf("is greater than %d\n",i);
        scanf("%c",&x[0]);
        getchar();
        if(x[0]=='n')
        {
            printf("your num %d",i);
            break;
        }
        else if(x[0]=='y')
        {
            continue;
        }
    }
}
