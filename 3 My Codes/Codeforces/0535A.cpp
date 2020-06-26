#include<bits/stdc++.h>
using namespace std;

void print_1_to_9(int n)
{
    switch(n)
    {
    case 1:
        printf("one");
        break;
    case 2:
        printf("two");
        break;
    case 3:
        printf("three");
        break;
    case 4:
        printf("four");
        break;
    case 5:
        printf("five");
        break;
    case 6:
        printf("six");
        break;
    case 7:
        printf("seven");
        break;
    case 8:
        printf("eight");
        break;
    case 9:
        printf("nine");
        break;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    //for(int n = 0; n < 100; n++){
    if(n >= 20)
    {
        switch(n/10)
        {
        case 2:
            printf("twenty");
            break;
        case 3:
            printf("thirty");
            break;
        case 4:
            printf("forty");
            break;
        case 5:
            printf("fifty");
            break;
        case 6:
            printf("sixty");
            break;
        case 7:
            printf("seventy");
            break;
        case 8:
            printf("eighty");
            break;
        case 9:
            printf("ninety");
            break;
        }

        if(n%10)
        {
            printf("-");
            print_1_to_9(n%10);
        }
    }
    else if(n > 0 && n < 10)
        print_1_to_9(n);
    else if(n == 0)
        printf("zero");
    else
    {
        switch(n%10)
        {
        case 0:
            printf("ten");
            break;
        case 1:
            printf("eleven");
            break;
        case 2:
            printf("twelve");
            break;
        case 3:
            printf("thirteen");
            break;
        case 5:
            printf("fifteen");
            break;
        case 8:
            printf("eighteen");
            break;
        default:
            print_1_to_9(n%10);
            printf("teen");
        }
    }
    //printf("\n");}
}
