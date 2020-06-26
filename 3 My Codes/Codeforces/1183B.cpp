#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int main()
{
    int q, n, k, i;
    pair <int, int> pi;
    int a;
    scanf("%d", &q);
    while(q--)
    {
        pi.ff = -1;
        pi.ss = 1000000000;
        scanf("%d %d", &n, &k);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a);
            pi.ff = max(pi.ff, max(1, a - k));
            pi.ss = min(pi.ss, a + k);
        }
        if(pi.ss - pi.ff + 1 <= 0)
            printf("-1\n");
        else
            printf("%d\n", pi.ss);
    }
}
