#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, i, k, temp;
    scanf("%d", &n);
    int a[n];
    FORAB(i, 0, n)
        scanf("%d %d", &temp, &a[i]);

    scanf("%d", &k);

    FORAB(i, 0, n)
    {
        if(a[i] >= k)
            break;

    }
    printf("%d", n - i);
}
