#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, maxa = 0, day = 0, m;

    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        if(m > maxa)
            maxa = m;
        if(maxa == i)
            day++;
    }
    printf("%d", day);
}
