#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int t, n, i, temp;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);

        int a[n];
        FORAB(i, 0, n)
            scanf("%d", &a[i]);

        //sort(a, a+n);

        int p = 0;
        FORAB(i, 0, n - 1)
        {
            //if(a[i] == a[i + 1])
                //continue;

            while(a[i] % 2 == 0)
            {
                p++;
                a[i] = a[i] / 2;
            }
        }

        while(a[n - 1] % 2 == 0)
        {
            p++;
            a[n - 1] = a[n - 1] / 2;
        }

        printf("%d\n", p);
    }
}
