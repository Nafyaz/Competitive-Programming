#include<bits/stdc++.h>
using namespace std;
int findone(int n)
{
    int x = 0;
    int temp = n;
    while(temp)
    {
        x += temp & 1;
        temp = temp >> 1;
    }
    return x;
}
int main()
{
    int T, i, n, ones, temp;
    scanf("%d", &T);

    for(i = 1; i <= T; i++)
    {
        ones = 0;
        scanf("%d", &n);

        ones = findone(n);

        while(1)
        {
            n++;
            if(findone(n) == ones)
            {
                printf("Case %d: %d\n", i, n);
                break;
            }
        }
    }
}
