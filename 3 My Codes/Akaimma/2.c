//2.Program to print number in words
#include<stdio.h>
#include<string.h>
int main()
{
    char c[1000];
    int i;
    printf("Input any number: ");
    scanf("%s",c);
    int l=strlen(c);

    for(i=0;i<l;i++)
    {
        switch(c[i])
        {
            case '1':
                printf("One ");
                break;
            case '2':
                printf("Two ");
                break;
            case '3':
                printf("Three ");
                break;
            case '4':
                printf("Four ");
                break;
            case '5':
                printf("Five ");
                break;
            case '6':
                printf("Six ");
                break;
            case '7':
                printf("Seven ");
                break;
            case '8':
                printf("Eight ");
                break;
            case '9':
                printf("Nine ");
                break;
        }
    }
}
