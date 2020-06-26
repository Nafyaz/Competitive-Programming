#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int n, k, i, total = 0;

    scanf("%d %d", &n, &k);

    int box;
    int a[k] = {0};

    FORAB(i, 0 , n)
    {
        scanf("%d", &box);
        a[box%k] ++ ;
    }

    FORAB(i, 1, k)
        total += min(a[i], a[k - i]);

    if((k&1) == 0)
        total -= (a[k/2] & 1);
    printf("%d", total + a[0] - (a[0] & 1));

}
