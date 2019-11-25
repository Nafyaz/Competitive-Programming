#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    if(!(n&1))
    {
        printf("-1");
        return 0;
    }

    for(int i = 0; i < n; i++)
        printf("%d ", i);
    printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d ", i);
    printf("\n");
    for(int i = 0; i < n; i++)
        printf("%d ", (i+i)%n);
}
