#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, c = 0;
    scanf("%d", &n);
    while(n >= 10)
    {
        n ++;
        while(n%10 == 0)
            n /= 10;
        c++;
    }
    printf("%d", c + 9);
}
