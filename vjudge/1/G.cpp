#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, T, a[3];
    scanf("%d", &T);

    for(i = 1; i <= T; i++)
    {
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        printf("Case %d: ", i);
        sort(a, a+3);

        a[0]*a[0] + a[1]*a[1] == a[2]*a[2] ? printf("yes\n") : printf("no\n");
    }
}
