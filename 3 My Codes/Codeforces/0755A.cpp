#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    if(n == 1)
    {
        printf("3");
        return 0;
    }
    if(n == 2)
    {
        printf("4");
        return 0;
    }
    printf("%d", n-2);
}
