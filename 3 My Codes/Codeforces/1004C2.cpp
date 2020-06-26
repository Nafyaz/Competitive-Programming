#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i;
    int Count[100010] = {0};
    long long ans = 0;
    set <int> s;
    bool taken[100010] = {0};

    scanf("%d", &n);
    int a[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        Count[a[i]] ++;
        s.insert(a[i]);
    }


    for(i = 0; i < n; i++)
    {
        Count[a[i]] --;
        if(Count[a[i]] && !taken[a[i]])
        {
            ans += s.size();
            taken[a[i]] = 1;
        }
        else if(!Count[a[i]] && !taken[a[i]])
        {
            s.erase(s.find(a[i]));
            ans += s.size();
        }
        else if(!Count[a[i]] && taken[a[i]])
            s.erase(s.find(a[i]));
    }
    printf("%lld", ans);
}
