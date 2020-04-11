#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int rec(int *a, int n, int i, int l, int sl)
{
    if(i == n)
        return sl;

    int temp;
    if (a[i] > l)
    {
        sl = l;
        l = a[i];
    }
    else if(a[i] > sl && a[i] != l) //input: 5 1 2 3 5 5
    {
        sl = a[i];
    }
    return rec(a, n, i + 1, l, sl);
}
int main()
{
    int n, i;
    scanf("%d", &n);
    int a[n];
    FORAB(i, 0, n)
        scanf("%d", &a[i]);
    printf("%d", rec(a, n, 0, 0, 0));
}
