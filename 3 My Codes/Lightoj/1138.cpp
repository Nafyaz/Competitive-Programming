#include<bits/stdc++.h>
using namespace std;

int zeros(int x)
{
    int ans = 0;
    while(x)
    {
        ans += x/5;
        x /= 5;
    }
    return ans;
}

int main()
{
    int q, t, caseno = 0, l, r, m, z;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &q);
        l = 1;
        r = 1000000000;
        while(l <= r)
        {
            m = (l+r)/2;
            z = zeros(m);
            if(z == q)
            {
                while(z == zeros(m))
                    m--;

                printf("Case %d: %d\n", ++caseno, m+1);
                break;
            }
            else if(z > q)
                r = m - 1;
            else
                l = m + 1;
        }
        if(l > r)
            printf("Case %d: impossible\n", ++caseno);
    }
}
