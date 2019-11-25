//lame bruteforce solution
#include<bits/stdc++.h>
using namespace std;

#define num 30009

int main()
{
    int a, b, c, d, e, p;
    int ans;


    while(scanf("%d", &p) == 1){
        ans = 0;

    for(a = 0; a <= p; a++)
    {
        for(b = 0; a+5*b <= p; b++)
        {
            for(c = 0; a+5*b+10*c <= p; c++)
            {
                for(d = 0; a+5*b+10*c+25*d <= p; d++)
                {
                    for(e = 0; a+5*b+10*c+25*d+50*e <= p; e++)
                        if(a+5*b+10*c+25*d+50*e == p)
                            ans++;
                }
            }
        }
    }

    if(ans > 1)
        printf("There are %d ways to produce %d cents change.\n", ans, p);
    else
        printf("There is only 1 way to produce %d cents change.\n", p);
    }
}
