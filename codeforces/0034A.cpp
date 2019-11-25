#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, i, mindiff = 10000, mini;
    scanf("%d", &n);
    int a[n + 1];

    FORAB(i, 0, n)
        scanf("%d", &a[i]);

    a[n] = a[0];

    FORAB(i, 0, n)
    {
        if(abs(a[i] - a[i + 1]) < mindiff)
        {
            mindiff = abs(a[i] - a[i + 1]);
            mini = i;
        }
    }
    printf("%d %d", (mini + 1), (mini + 1) % n + 1);
}
