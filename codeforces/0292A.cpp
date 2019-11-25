#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, t, c, time, maxq;
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &t, &c);
        if(i == 0)
        {
            time = t + c;
            maxq = c;
            continue;
        }
        time = max(time, t) + c;
        maxq = max(maxq, time - t);
    }
    printf("%d %d", time, maxq);
}
