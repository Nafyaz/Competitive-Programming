#include<bits/stdc++.h>
using namespace std;
void show(deque<int> d)
{
    while(!d.empty())
    {
        printf("%d ", d.front());
        d.pop_front();
    }
    printf("\n");
}
int main()
{
    int n, k, l, r, i;
    scanf("%d %d", &n, &k);
    int a[n], ans[n];
    deque <int> q;

    l = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        while(!q.empty() && q.back() < a[i])
        {
            q.pop_back();
            while(!q.empty() && q.front() != a[l])
                l++;
        }

        q.push_back(a[i]);
        if(i - l >= k)
        {
            q.pop_front();
            while(q.front() != a[l])
                l++;
        }
        ans[i] = q.front();
        show(q);
    }

    for(i = 0; i < n; i++)
        printf("%d ", ans[i]);
}
