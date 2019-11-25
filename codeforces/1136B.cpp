#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    if(k == 1 || k == n)
        printf("%d", 3*n);
    else if (k <= n/2)
        printf("%d", 3*n+k-1);
    else
    {
        k = n - k + 1;
        printf("%d", 3*n+k-1);
    }





}
