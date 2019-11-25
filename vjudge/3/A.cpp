#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int T, n, i, b, k, l;
    scanf("%d", &T);
    while(T--)
    {
        b = 0;
        k = 0;
        l = 0;
        scanf("%d", &n);
        char a[55];
        FORAB(i, 0, n)
        {
            scanf("%s", a);
            if(a[0] == 'b')
                b ++;
            else if(a[0] == 'k')
                k ++;
            else if(a[0] == 'l')
                l ++;
        }
        printf("%d\n", min(min(b/2, k),l));
    }
}
