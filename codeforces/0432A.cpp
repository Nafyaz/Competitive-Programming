#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, i, total = 0;
    scanf("%d %d", &n, &k);
    int y[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &y[i]);
        if(y[i] + k <= 5) total++ ;
    }
    printf("%d\n", total/3);
}
