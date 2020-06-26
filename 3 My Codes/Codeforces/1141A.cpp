#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, m, i;
    scanf("%d %d", &n, &m);

    if(m % n != 0)
    {
        printf("-1");
        return 0;
    }

    int c = 0, div = m/n;
    while(div % 2 == 0)
    {
        c++;
        div /= 2;
    }

    while(div % 3 == 0)
    {
        c++;
        div /= 3;
    }

    div == 1? printf("%d", c) : printf("-1");
}
