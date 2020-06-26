#include<bits/stdc++.h>
using namespace std;
bool flag;
stack <int> s;
long long fact[21], sum, n;
void prep()
{
    for(int i = 1; i <= 20; i++)
        fact[i] = fact[i-1] * i;
}

void func(int x)
{
    for(;x >= 0; x--)
    {
        if(sum + fact[x] < n)
        {
            s.push(x);
            sum += fact[x];
        }
        else if(sum + fact[x] == n)
        {
            s.push(x);
            flag = 1;
            break;
        }
    }
}

int main()
{
    fact[0] = 1;
    prep();
    int t, caseno = 0, i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        while(!s.empty())
            s.pop();
        sum = 0;
        flag = 0;
        func(20);
        if(flag)
        {
            printf("Case %d: ", ++caseno);
            while(s.size() != 1)
            {
                printf("%d!+", s.top());
                s.pop();
            }
            printf("%d!\n", s.top());
        }
        else
            printf("Case %d: impossible\n", ++caseno);
    }
}
