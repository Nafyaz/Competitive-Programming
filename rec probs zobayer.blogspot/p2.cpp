#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

void rec(int i, int n, int *a)
{
    if(i <= (n - 1) / 2)
    {
        printf("%d %d\n", a[i], a[n - i - 1]);
        rec(i + 1, n, a);
    }
}
int main()
{
    int i, n;
    scanf("%d", &n);
    int a[n];

    FORAB(i, 0, n)
        scanf("%d", &a[i]);

    rec(0, n, a);
}
