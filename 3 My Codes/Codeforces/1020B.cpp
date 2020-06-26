#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j;
    scanf("%d", &n);
    int p[n];

    for(i = 0; i < n; i++)
        scanf("%d", &p[i]);

    bool x[n];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            x[j] = 0;

        j = i;
        while(!x[j])
        {
            x[j] = 1;
            j = p[j] - 1;
        }
        printf("%d ", j+1);
    }
}
