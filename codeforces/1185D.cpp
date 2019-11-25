#include<bits/stdc++.h>
using namespace std;

int a[100010], b[100010], n;

bool is_ap(int x)
{
    int dis = a[1] - a[0], prev = 0;
    for(int i = 0; i < n; i++)
    {
        if(i == x)
            continue;
        if(a[i] - a[prev] != dis)
            return 0;

        prev++;
        if(prev == x)
            prev++;
    }
    return 1;
}
int main()
{
    int i, del = 0, idx, flag = 0;
    scanf("%d", &n);


    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    sort(a, a+n);

    for(i = 0; i < n; i++)
        a[i] -= a[0];

    int c = a[1];

    for(i = 1; i < n; i++)
    {
        if(a[i] == a[i-1])
        {
            printf("-1a");
            return 0;
        }
        if(!(a[i] % c == 0 && (a[i] / c == i || a[i] / c == i-1)))
        {
            printf("%d %d\n", i, a[i]);
            del ++;
            idx = i;
        }
    }
    //printf("%d\n", del);
    if(del == 0)
        printf("1");

    else if(del == 1)
    {
        if(is_ap(find(b, b+n, a[idx]) - b))
            printf("%d", find(b, b + n, a[idx]) - b + 1);
        else
            printf("-1b");
    }

    else if(del == n-2)
    {
        if(is_ap(0))
            printf("1");
        else
            printf("-1c");
    }
    else
        printf("-1d");
}
