#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a, b, i;
    scanf("%d %d", &n, &m);

    for(i = 0; i < m; i++)
        scanf("%d %d", &a, &b);

    for(i = 0; i < n; i++)
        i&1 ? printf("1") : printf("0");
}
