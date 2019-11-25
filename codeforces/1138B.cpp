#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, i, zero = 0, clown = 0, acro = 0, both = 0, temp;
    scanf("%d", &n);
    int a[n][2];

    FORAB(i, 0, n)
        scanf("%d", &a[i][0]);
    FORAB(i, 0, n)
        scanf("%d", &a[i][1]);

    FORAB(i, 0, n)
    {
        if(a[i][0] == 1 && a[i][1] == 1)
            both ++;
        else if(a[i][0] == 1 && a[i][1] == 0)
            clown ++;
        else if(a[i][0] == 0 && a[i][1] == 1)
            acro ++;
        else
            zero ++;
    }
    if(acro > clown)
    {
        temp = clown;
        clown = acro;
        acro = temp;
    }
}
