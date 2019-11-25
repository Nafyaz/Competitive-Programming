#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, T, n;
    scanf("%d", &T);

    for(i = 1; i <= T; i++)
    {
        int s = 0, dust;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &dust);
            if(dust > 0)
                s += dust;
        }
        printf("Case %d: %d\n", i, s);
    }
}
