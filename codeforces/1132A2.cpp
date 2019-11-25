#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(a != d)
        printf("0");

    else if (c && a>0)
        printf("1");

    else if( !c )
        printf("1");
    else
        printf("0");
}
