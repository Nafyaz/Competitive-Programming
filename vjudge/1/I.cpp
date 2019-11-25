#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, i, c = 0, j;
    scanf("%d %d", &n, &x); //n = size of the table, x = number we are looking for

    int sq = sqrt(x);

    for(i = 1; i <= sq && i <= n; i++)
    {
        if(x % i == 0)
        {
            j = x / i;
            if(i == j)
                c++;
            else if(j <= n)
                c+=2;
        }
    }
    printf("%d\n", c);
}
