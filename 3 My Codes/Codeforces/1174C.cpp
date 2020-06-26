#include<bits/stdc++.h>
using namespace std;
#define N 100010
int p[N], x;

void lamesieve()
{
    int j, i, val;
    for(i = 2; i < N; i++)
    {
        val = sqrt(i) + 1;
        for(j = 2; j < val; j++)
        {
            if(i % j == 0)
            {
                p[i] = p[j];
                break;
            }
        }
        if(p[i] == 0)
            p[i] = ++x;
    }
}

int main()
{
    lamesieve();
    int i, n;

    scanf("%d", &n);
    for(i = 2; i <= n; i++)
        printf("%d ", p[i]);
}
