#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3], d;
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    scanf("%d", &d);

    sort(a, a+3);
    printf("%d", max(0, d - a[1] + a[0]) + max(0, d - a[2] + a[1]));
}
