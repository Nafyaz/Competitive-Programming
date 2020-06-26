#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        switch(i%4)
        {
        case 0:
            printf("a");
            break;
        case 1:
            printf("b");
            break;
        case 2:
            printf("c");
            break;
        case 3:
            printf("d");
            break;
        }
    }
}
