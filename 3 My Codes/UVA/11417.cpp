#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    while(scanf("%d", &N))
    {
        if(N == 0)
            return 0;
        int G=0, i, j;
        for(i=1;i<N;i++)
        for(j=i+1;j<=N;j++)
            G+=__gcd(i,j);
        printf("%d\n", G);
    }
}


