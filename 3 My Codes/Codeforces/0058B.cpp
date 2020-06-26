//manusher code -_-
#include <stdio.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i=n;i>=1;i--)
    {
        if(n%i==0)
        {
            printf("%d ", i);
            n=i;
        }
    }

    return 0;
}
