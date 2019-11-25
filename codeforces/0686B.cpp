#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, k, x, y, flag;
    scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = n - 1; i >= 0; i--)
    {
        for(j = 0; j <= i; j++)
        {
            if(a[j] <= a[j+1])
                continue;
            k = j;
            while(k < n - 1 && a[k] > a[k + 1])
            {
                swap(a[k], a[k+1]);
                k += 2;
            }
            printf("%d %d\n", j+1, k);
        }
    }
}
