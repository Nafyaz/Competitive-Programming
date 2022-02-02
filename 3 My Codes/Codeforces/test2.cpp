#include <bits/stdc++.h>
using namespace std;

int n;

int oj[1000007];
int roz[1000007];

double ocz[1000007];

int main()
{
    scanf("%d", &n);
    for (int i=2; i<=n; i++)
    {
        scanf("%d", &oj[i]);
    }
    for (int i=n; i; i--)
    {
        roz[i]++;
        roz[oj[i]]+=roz[i];
    }
    ocz[1]=1.0;
    for (int i=2; i<=n; i++)
    {
        ocz[i]=ocz[oj[i]]+(roz[oj[i]]-roz[i]-1.0)/2.0+1.0;
    }
    for (int i=1; i<=n; i++)
    {
        printf("%.8lf ", ocz[i]);
    }
    printf("\n");
    return 0;
}
