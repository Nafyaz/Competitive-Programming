#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int T, i, i2, n;
    scanf("%d", &T);
    while(T--)
    {
        int ans = 0;
        scanf("%d", &n);
        int a[n], b[n], r[n], c[n];
        FORAB(i, 0, n)
        {
            scanf("%d %d", &r[i], &c[i]);
            a[i] = r[i];
            b[i] = c[i];
        }
        sort(a, a+n);
        sort(b, b+n);

        int x[n] = {0}, y[n] = {0}, j = 0, k = 0;
        x[0] = 1;
        y[0] = 1;
        FORAB(i, 1, n)
        {
            if(a[i] != a[i - 1])
                j++;
            if(b[i] != b[i - 1])
                k++;

            x[j] = x[j - 1];
            x[j] ++;

            y[k] = y[k - 1];
            y[k] ++;
        }
        FORAB(i, 0, j)
        {
            FORAB(i2, 0, k)
            {
                if(a[x[i] - 1 == b[y[i2] - 1)
                    ans += x[i]*y[i2];

            }
        }

    }
}
