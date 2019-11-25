#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k, d, i;
    scanf("%d %d", &k, &d);
    if(k > 1 && d == 0)
    {
        printf("No solution");
        return 0;
    }

    for(i = 1; i < k; i++)
        printf("9");
    printf("%d", d);
}
