#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, T, mypos, lifpos;
    scanf("%d", &T);
    for(i = 1; i <=T; i++)
    {
        scanf("%d %d", &mypos, &lifpos);
        if(mypos > lifpos)
            printf("Case %d: %d\n", i, (2*mypos - lifpos)*4 + 19);
        else
            printf("Case %d: %d\n", i, lifpos*4 + 19);
    }
}
