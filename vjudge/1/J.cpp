#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);

    long long a, b, x, y, temp;
    while(T--)
    {
        scanf("%lld %lld", &a, &b);
        x = a;
        y = b;
        while(a != 0)
        {
            temp = a;
            a = b % a;
            b = temp;
        }
        printf("%lld %lld\n", b, x/b*y);
    }
}
