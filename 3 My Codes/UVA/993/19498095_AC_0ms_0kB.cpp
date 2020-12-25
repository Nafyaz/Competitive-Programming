#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, t;
    stack <int> q;
    scanf("%d", &t);
    while(t--)
    {
        while(!q.empty()) q.pop();
        scanf("%d", &n);
        for(i = 9; i > 1; i--)
        {

            if(n < 10)
            {
                q.push(n);
                n = 1;
                break;
            }
            while(n%i == 0)
            {
                q.push(i);
                n /= i;
            }
        }
        if(n != 1)
        {
            printf("-1\n");
            continue;
        }
        while(!q.empty())
        {
            printf("%d", q.top());
            q.pop();
        }
        printf("\n");
    }
}
