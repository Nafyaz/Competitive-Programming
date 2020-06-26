#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, k, ans;
    scanf("%d", &t);
    while(t--)
    {
        ans = 1;
        scanf("%d %d", &n, &k);
        if(k == 1)
        {
            if((n+1)/2 & 1)
                ans = 0;
        }
        else
        {
            if((n/k) & 1)
                ans = 0;
            n = n%k;
            if((n+1)/2 & 1)
                ans = ans^1;
        }
        ans? printf("Bob\n") : printf("Alice\n");
    }
}
