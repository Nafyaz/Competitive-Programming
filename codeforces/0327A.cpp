//got rid of a loop
#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for( i = a; i < b; i++)

int main()
{
    int n, i, j, maxone = 0, nowone, k;
    scanf("%d", &n);
    int a[n], total = 0;

    FORAB(i, 0, n)
    {
        scanf("%d", &a[i]);
        total += a[i];
    }

    FORAB(i, 0, n)
    {
        nowone = total;
        FORAB(j, i, n)
        {
            if(a[j])
                nowone --;
            else
                nowone ++;

            maxone = max(maxone, nowone);
        }
    }
    printf("%d", maxone);
}
