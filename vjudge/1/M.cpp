#include<bits/stdc++.h>
using namespace std;

int fun(int n)
{
    if(n == 1)
        return 1;
    if(n % 2 == 0)
    {
        return 1 + fun(n / 2);;
    }
    else
    {
        return 1 + fun(3*n + 1);;
    }
}

int main()
{
    int i, j, m, x, y, a, b;
    while(scanf("%d %d", &a, &b) == 2)
    {
        m = 0;
        x = min(a, b);
        y = max(a, b);
        for(i = x; i <= y; i++)
        {
            j = fun(i);
            if(j > m)
                m = j;
        }
        printf("%d %d %d\n", a, b, m);
    }
}
