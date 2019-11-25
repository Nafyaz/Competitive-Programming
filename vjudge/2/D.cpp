#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);

    if(n % 4 == 0)
        printf("%d %d", n/2, n/2);

    else if(n % 2 == 0)
        printf("%d %d", n - 4, 4);

    else
    {
        switch(n % 12)
        {
        case 11:
            printf("%d %d", n - 8, 8);
            break;

        case 9:
            printf("%d %d", n - 6, 6);
            break;
        case 7:
            printf("%d %d", n - 4, 4);
            break;

        case 5:
            printf("%d %d", n - 8, 8);
            break;
        case 3:
            printf("%d %d", (n - 3)/12*9, (n - 3)/4 + 3);
            break;
        case 1:
            printf("%d %d", n - 4, 4);
            break;
        }
    }
}
