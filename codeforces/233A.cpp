#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    if(n % 2 == 1)
    {
        printf("-1");
        return 0;
    }
    for(int i = 1; i <= n; i++)
        i%2 ? printf("%d ", i+1) : printf("%d ", i-1);
}
