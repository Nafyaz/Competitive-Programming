#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, x, prev;
    scanf("%d", &n);
    int diff[n] = {0};

    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if(i == 0)
        {
            prev = x;
            continue;
        }
        if(x > prev)
            diff[i] = 1;
        else if(x < prev)
            diff[i] = -1;
        else
            diff[i] = 0;

        prev = x;
    }

    int sign, ans = 1, m = 1;
    i = 0;
    while(i < n)
    {
//        printf("%d ", m);
        if(diff[i] == 0)
        {
            while(i < n && diff[i] == 0)
                i++;
            if(i == n)
                break;
            else
            {
                m = 1;
                sign = diff[i];
                i++;
                continue;
            }
        }

        if(diff[i] == sign)
        {
            m = 1;
            i++;
            continue;
        }

        else if (diff[i] != 0)
        {
            sign *= -1;
            i++;
            m++;
            ans = max(ans, m);
        }

    }

    printf("%d", ans + 1);
}
