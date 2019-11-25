#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    stack <int> s;
    while(b>a)
    {
        s.push(b);
        if(b%2 == 0)
            b /= 2;
        else if(b%10 == 1)
            b = (b-1)/10;
        else
        {
            printf("NO");
            return 0;
        }
    }
    if(b < a)
    {
        printf("NO");
        return 0;
    }
    else
    {
        s.push(b);
        printf("YES\n%d\n", s.size());
        while(!s.empty())
        {
            printf("%d ", s.top());
            s.pop();
        }
    }
}
