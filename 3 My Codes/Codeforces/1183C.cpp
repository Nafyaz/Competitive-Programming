#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q, k, n, a, b, ans, temp;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d %d %d %d", &k, &n, &a, &b);

        if((k - 1)/b < n)
            printf("-1\n");
        else
        {
            temp = k;
            ans = (temp - 1)/a;
            temp -= ans*a;
            while(ans + (temp - 1)/b < n)
            {
                ans--;
                temp = k - ans*a;
            }
            printf("%d\n", min(ans, n));
        }
    }
}
