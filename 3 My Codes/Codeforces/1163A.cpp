#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int g, x = n - m;
    if(m == 0)
    {
        printf("1");
        return 0;
    }
    g = min(n/2, x);
    x = x - g;
    if(n % 2 == 1 && x)
        x--;
    while(x)
    {
        x--;
        g--;
    }
    printf("%d", g);
}
