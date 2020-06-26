#include<bits/stdc++.h>
using namespace std;

int main()
{
    int p[4], a, b;
    scanf("%d %d %d %d %d %d", &p[0], &p[1], &p[2], &p[3], &a, &b);
    sort(p, p+4);

    if(p[0] <= a)
        printf("0");
    else if(p[0] <= b)
        printf("%d", p[0] - a);
    else
        printf("%d", b - a + 1);
}
