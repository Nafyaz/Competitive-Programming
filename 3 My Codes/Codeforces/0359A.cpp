#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int i, j, n, m, a, ans = 4;
    scanf("%d %d", &n, &m);

    FORAB(i, 0, n)
    {
        FORAB(j, 0, m)
        {
            scanf("%d", &a);
            if(a && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
                ans = 2;
        }
    }
    printf("%d", ans);
}

