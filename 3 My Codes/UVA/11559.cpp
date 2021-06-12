#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j;
    int N, B, H, W, p, a, minprice, price, suitable;
    while(scanf("%d %d %d %d", &N, &B, &H, &W) == 4)
    {
        minprice = INT_MAX;
        for(i = 0; i < H; i++)
        {
            suitable = 0;
            scanf("%d", &p);

            for(j = 0; j < W; j++)
            {
                scanf("%d", &a);
                if(a >= N)
                    suitable = 1;
            }

            price = N * p;

            if(price > B)
                suitable = 0;

            if (suitable && price < minprice)
                minprice = price;
        }
        minprice == INT_MAX? printf("stay home\n") : printf("%d\n", minprice);
    }

}
