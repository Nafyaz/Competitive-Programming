#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, T, d, n, n2, temp, temp2;
    scanf("%d", &T);

    for(i = 1; i <= T; i++)
    {
        scanf("%d", &n);
        d = 0;
        temp = n;
        /*My plan is to find the first "01" and make it "10"
        e.g. 1011 will be 1101*/

        while(temp)
        {
            d++;
            temp2 = (temp ^ 2) & 3;
            if(temp2 == 3)
            {
                n2 = n - (1 << (d-1)) + (1 << d);//n2 is what we get modifying once
                break;
            }
            temp = temp >> 1;
        }
        /*Problem: 101100 will become 110100. but I want 110001
        So, the first "01" should be replaced by "10" and if
        there are more than "010" is not the first "01" then the first "1"
        should be placed as the first digit*/

        //check "101"
        if(d == 1)
        {
            printf("Case %d: %d\n", i, n2);
            continue;
        }
        temp = n;
        temp2 = ((temp >> (d - 2)) ^ 5) & 7;
        if(temp2 != 7 && !(temp & 1))
        {
            /*this will be of type ...0100000 or ...01111110000 or ...0111111
            find where that rascal first 1 is
            oops, we just canceled out ...010000 in temp2 != 7.
            so, we have ...011110000 and ...011111
            oops, we have canceled ...011111 as well in !(temp & 1) :p */
            d = 0;
            while(temp)
            {
                d++;
                if(temp & 1)
                    break;
                temp = temp >> 1;
            }
            n2 = n2 - (1 << (d - 1)) + 1;

        }
        printf("Case %d: %d\n", i, n2);
    }
}
