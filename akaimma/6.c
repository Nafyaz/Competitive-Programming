#include<stdio.h>
int main()
{
    int i,j,a[4],count=0;
    for(i=0;i<4;i++)
        scanf("%d",&a[i]);

    int b[4]={0};
    for(i=0;i<4;i++)
    {
        for(j=i;j<4;j++)
        {
            if(a[i]==a[j])
                b[i]++;
        }
    }
    for(i=0;i<4;i++)
    {
        if(b[i]>1)
            count=count+b[i]-1;
    }
    printf("%d",count);
}
