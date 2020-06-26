//shihabsikder er code

#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a = 0, count_1 = 0, count_0 = 0, count_0max = -1;
    while(n--)
    {
        scanf("%d", &a);
        if(a == 1)
        {
            count_1++;
            if(count_0 > 0)
                count_0--;
        }
        if(a==0)
        {
            count_0++;
            if(count_0 > count_0max)
                count_0max = count_0;
        }
    }
    printf("%d", count_0max + count_1);
}
