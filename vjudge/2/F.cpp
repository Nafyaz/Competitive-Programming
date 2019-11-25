#include<bits/stdc++.h>
using namespace std;
void printbinaryrev(unsigned int n)
{
    int i;
    for(;n; n /= 2)
        printf("%u", n%2);
    printf("\n");
}
int main()
{
    /*unsigned int n = 4;
    int i;
    for(i = 1; i <= 31; i+=3)
    {
        n = n + (1<<i);
    }
    printf("%u", n);*/
    int i, T, a, b, zeros, j;
    unsigned int n2, n = 2454267030;
    //printbinaryrev(n);
    scanf("%d", &T);
    for(i = 1; i <= T; i++)
    {
        scanf("%d %d", &a, &b);
        zeros = 0;
        n2 = n;
        //printbinaryrev(n2);
        for(j = a; j <= b; j++)
            zeros += ((n2 ^ (1<<j)) & (1<<j)) >> j;

        printf("Case %d: %d\n", i, zeros);
    }
}
