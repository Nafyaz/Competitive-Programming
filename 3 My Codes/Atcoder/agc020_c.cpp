#include<bits/stdc++.h>
using namespace std;

bitset<2000009> dp;

int main()
{
    int n, i, j, a[2009], sum = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    dp[0] = 1;


    for(i = 0; i < n; i++)
    {
        dp |= (dp << a[i]);
//        cout << dp << endl;
    }

    for(i = sum/2; i >= 0; i--)
    {
        if(dp[i])
        {
            printf("%d", sum - i);
            return 0;
        }
    }
}
