#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, p, m, a, b, c, d, e;
    scanf("%d", &n);
    char s[n][25];
    int point[n] = {0};
    for(i = 0; i < n; i++)
    {
        scanf("%s", s[i]);
        scanf("%d %d %d %d %d %d %d", &p, &m, &a, &b, &c, &d, &e);
        point[i] = 100*p - 50*m + a + b + c + d + e;
    }
    int maxpoint = 0, maxi;
    for(i = 0; i < n; i++)
    {
        if(maxpoint < point[i])
        {
            maxpoint = point[i];
            maxi = i;
        }
    }
    printf("%s", s[maxi]);
}
