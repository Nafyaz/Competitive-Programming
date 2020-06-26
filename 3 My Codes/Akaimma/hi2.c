#include<stdio.h>
int main()
{
    int n = 6, i, j;

    int marks[] = {60, 65, 22, 44, 52};
    int marks2[n];

    for(i = 0; i < n; i++)
    {
        if(i < 2)
            marks2[i] = marks[i];
        else if(i == 2)
            marks2[i] = 25;
        else
            marks2[i] = marks[i - 1];
    }

    for(i = 0; i < n; i++)
        printf("%d ", marks2[i]);
}
