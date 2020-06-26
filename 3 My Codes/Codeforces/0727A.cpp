#include<bits/stdc++.h>
using namespace std;

long long b, found = 0;
deque <long long> d;
void dfs(long long a)
{
    d.push_back(a);
    if(found)
    {
        return;
    }
    if(a == b)
    {
        found = 1;
        int len = d.size();
        printf("YES\n%d\n", len);

        for(int i = 0; i < len; i++)
        {
            printf("%lld ", d[i]);
        }
        return;
    }
    if(a > b)
        return;

    dfs(2*a);
    d.pop_back();
    dfs(10*a+1);
    d.pop_back();
}

int main()
{
    long long a;
    scanf("%lld %lld", &a, &b);
    dfs(a);
    if(!found)
        printf("NO");
}
