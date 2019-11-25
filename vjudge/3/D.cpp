#include<bits/stdc++.h>
using namespace std;

#define FORAB(i, a, b) for(i = a; i < b; i++)

int main()
{
    int T, time, a, b;
    scanf("%d", &T);
    while(T--)
    {
        int n, d, r;
        scanf("%d %d %d", &n, &d, &r);
        int space1[n] = {0}, space2[n] = {0};
        time = 1;
        a = b = 0;
        while(1)
        {
            a = (a + d) % n;
            b = (b + r) % n;

            if(space1[b] == 1 || space2[a] == 1 || a == b)
            {
                printf("%d\n", time);
                break;
            }
            space1[a] = 1;
            space2[b] = 1;

            time++;
        }
    }
}
