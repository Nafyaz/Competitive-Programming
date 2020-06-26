#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, a, temp, i, len, maxlen;
    scanf("%d", &n);
    int sign[n];
    scanf("%d", &a);
    n = n - 1;

    FORAB(i, 0, n)
    {
        scanf("%d", &temp);
        if(temp > a)
            sign[i] = 1;
        else if(temp < a)
            sign[i] = -1;
        else
            sign[i] = 0;
        a = temp;
    }

    //FORAB(i, 0, n)
      //  printf("%d ", sign[i]);

    maxlen = 1;
    if(sign[i] == 0)
        len = 0;
    else
        len = 1;

    FORAB(i, 1, n)
    {
        if(sign[i] + sign[i - 1] == 0 && sign[i] != 0)
            len ++;
        else
        {
            if(len > maxlen)
                maxlen = len;
            if(sign[i] == 0)
                len = 0;
            else
                len = 1;
        }
    }
    if(len > maxlen)
            maxlen = len;

    printf("%d", maxlen + 1);
}
