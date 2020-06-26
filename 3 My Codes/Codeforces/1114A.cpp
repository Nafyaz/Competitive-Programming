#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, x, y, z;

    scanf("%d %d %d", &x, &y, &z);
    scanf("%d %d %d", &a, &b, &c);

    if(a < x)
    {
        printf("NO");
        return 0;
    }
    if(a - x + b < y)
    {
        printf("NO");
        return 0;
    }
    if(a-x + b-y + c < z)
    {
        printf("NO");
        return 0;
    }
    printf("YES");
}
