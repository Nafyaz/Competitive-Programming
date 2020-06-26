#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int T, i, n, r, ri, a;
    scanf("%d", &T);

    while(T--)
    {
        ri = 1500;
        scanf("%d %d", &n, &r);
        FORAB(i, 0, n)
        {
            scanf("%d", &a);
            ri += a;
        }
        if(ri == r)
            printf("Correct\n");
        else
            printf("Bug\n");
    }
}
