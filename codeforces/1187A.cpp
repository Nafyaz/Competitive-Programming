#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T, n, s, t;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d %d", &n, &s, &t);
        printf("%d\n", max(n - s, n - t) + 1);
    }
}
