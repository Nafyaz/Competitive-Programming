#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int temp;
    while(b)
    {
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int main()
{
    int t, n, a, b, sum;
    scanf("%d", &t);
    while(t--)
    {
        sum = 0;
        scanf("%d", &n);

        scanf("%d", &a);

        sum += a;
        n--;
        if(n == 0)
            printf("%d 1\n", a);
        else
        {
            while(n--)
            {
                scanf("%d", &b);
                sum += b;
                a = gcd(a, b);
            }
            printf("%d %d\n", a, sum/a);
        }
    }
}
