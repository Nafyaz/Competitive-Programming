#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, m = -10000000, mi, zero = 0;
    scanf("%d", &n);
    int a[n];
    queue <int> pos, neg;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i] >= 0)
            a[i] = -a[i] - 1;

        if(a[i] == -1)
            zero++;

        if(m < -a[i] - 1)
        {
            m = -a[i] - 1;
            mi = i;
        }

        neg.push(a[i]);
        pos.push(-a[i] - 1);
    }
    if(!(n&1))
    {
        while(!neg.empty())
        {
            printf("%d ", neg.front());
            neg.pop();
        }
        return 0;
    }

    if(zero == n)
    {
        while(!pos.empty())
        {
            printf("%d ", pos.front());
            pos.pop();
        }
        return 0;
    }

    if(zero == n-1)
    {
        while(!pos.empty())
        {
            if(pos.front() != 0)
                printf("%d ", pos.front());
            else
                printf("%d ", neg.front());

            pos.pop();
            neg.pop();
        }
        return 0;
    }

    i = 0;
    while(!pos.empty())
    {
        if(pos.front() == 0)
        {
            //zero--;
            printf("%d ", neg.front());
        }
        else if(i == mi)
            printf("%d ", pos.front());
        else
            printf("%d ", neg.front());

        i++;
        pos.pop();
        neg.pop();
    }
}
