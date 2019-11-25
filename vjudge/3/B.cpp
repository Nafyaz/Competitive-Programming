#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, a, b, c, d;
    scanf("%d", &n);

    while(n --)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);

        b * log(a) > d * log(c)? printf(">\n") : printf("<\n");
        //printf("%lf %lf\n", b * log(a), d * log(c));
    }
}
