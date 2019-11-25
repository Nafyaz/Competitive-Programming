#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, T, a[3];
    scanf("%d", &T);
    for(i = 1; i <= T; i++)
    {
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        sort(a, a + 3);
        printf("Case %d: %d\n", i, a[1]);
    }
}
