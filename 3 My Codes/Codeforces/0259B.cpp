#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int a[9], i;
    FORAB(i, 0, 9)
        scanf("%d", &a[i]);

    int ab, cd, ef;
    ab = a[1] + a[2];
    cd = a[3] + a[5];
    ef = a[6] + a[7];

    if(ab > cd)
    {
        if(cd > ef)
        {
            a[0] = 3;
            a[4] = 2;
            a[8] = 1;
        }
        else if(ab > ef)
        {
            a[0] = 3;
            a[4] = 1;
            a[8] = 2;
        }
        else
        {
            a[0] = 2;
            a[4] = 3;
            a[8] = 1;
        }
    }
    else
    {
        if(ab > ef)
        {
            a[0] = 2;
            a[4] = 1;
            a[8] = 3;
        }
        else if()
    }
}
