#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, i, j;
    scanf("%d %d %d", &a, &b, &c);
    for(i = 0; a*i <= c; i++)
    {
        if((c - a*i) % b == 0)
        {
            printf("Yes");
            return 0;
        }
    }
    printf("No");
}
