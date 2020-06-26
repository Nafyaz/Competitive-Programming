#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, c = 0;
    int o = 0, e = 0;
    scanf("%d", &n);
    int a[n], nowodd, noweven, temp, fixodd = 0, fixeven = 0;
    //fixodd and fixeven are sum of odd or even numbers upto i-th number

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if(i % 2 == 0)
            o += a[i];
        else
            e += a[i];
    }
    for(i = 0; i < n; i++)
    {
        nowodd = 0;
        noweven = 0;
        if(i % 2 ==0)
        {
            nowodd = fixodd + e;
            noweven = fixeven + o - a[i];
        }
        else
        {
            nowodd = fixodd + e - a[i];
            noweven = fixeven + o;
        }


        if(i % 2 == 0)
        {
            o -= a[i];
            fixodd += a[i];
        }
        else
        {
            e -= a[i];
            fixeven += a[i];
        }

        if(nowodd == noweven)
            c++;
    }
    printf("%d\n", c);
}
