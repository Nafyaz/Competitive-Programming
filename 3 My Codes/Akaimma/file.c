#include<stdio.h>
#include<stdlib.h>
int main()
{
    double a[5] = {1.4, 0.5, -14.123, 10, 2.51};
    int i;

    FILE *fp;
    if((fp = fopen("bye.txt", "wb")) == NULL)
    {
        printf("Cannot open file");
        exit(1);
    }


    if((fwrite(a, sizeof(a), 1, fp)) != 1)
    {
        printf("Write error occured");
        exit(1);
    }
    fclose(fp);

    for(i = 0; i < 5; i++)
        a[i] = -1;

    if((fp = fopen("bye.txt", "rb")) == NULL)
    {
        printf("Cannot open file");
        exit(1);
    }


    if(fread(a, sizeof(a), 1, fp) != 1)
    {
        printf("Read error");
        exit(1);
    }


    for(i = 0; i < 5; i++)
        printf("%lf ", a[i]);

    fclose(fp);
}
