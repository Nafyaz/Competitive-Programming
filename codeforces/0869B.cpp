#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, i, ans = 1;
    scanf("%I64d %I64d", &a, &b);

    if(b == 0)
        printf("1");
    else if(b-a >= 5)
        printf("0");
    else
    {
        for(i = a+1; i <= b; i++)
        {
            /*if(i % 5 == 0)
            {
                if(b - a >=2)
                    printf("0");
                else
                    printf("5");
                return 0;
            }*/
            ans = (ans * (i%10)) % 10;
        }
        printf("%I64d", ans);

    }

}
