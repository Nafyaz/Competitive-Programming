#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("out.txt", "w", stdout);
    int i, j;
    int N, B, H, W, p, a, minprice, price, suitable;
    while(scanf("%d %d %d %d", &N, &B, &H, &W) == 4)
    {
        minprice = 100000000;
        for(i = 0; i < H; i++)
        {
            suitable = 1;
            price = 0;
            scanf("%d", &p);
            for(j = 0; j < W; j++)
            {
                scanf("%d", &a);
                if(a < N)
                    suitable = 0;

            }
            price += N * p;
            if(price > B)
                suitable = 0;

            if (suitable && price < minprice)
                minprice = price;
        }
        minprice == 100000000? printf("stay home\n") : printf("%d\n", minprice);
    }

}
