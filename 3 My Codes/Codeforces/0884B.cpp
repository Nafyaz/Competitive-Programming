#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, x, a, sum = 0;
    scanf("%d %d", &n, &x);

    for(i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        sum += a;
    }
    sum + n - 1 == x? printf("YES") : printf("NO");
}
