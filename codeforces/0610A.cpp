#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    if(n&1)
    {
        printf("0");
        return 0;
    }
    n = n/2;
    printf("%d", (n+1)/2 - 1);
}
