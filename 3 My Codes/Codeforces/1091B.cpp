#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j;
    scanf("%d", &n);
    int x[n], y[n], a[n], b[n];
    for(i = 0; i < n; i ++)
        scanf("%d %d", &x[i], &y[i]);
    for(i = 0; i < n; i ++)
        scanf("%d %d", &a[i], &b[i]);

    vector <pair<int, int> > ans;
    vector <int> numbers;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            ans.push_back(make_pair(x[i] + a[j], y[i] + b[j]));
    }
    int len = ans.size();
    for(i = 0; i < len; i++)
    {
        if(count(ans.begin(), ans.end(), ans[i]) == n)
        {
            printf("%d %d", ans[i].first, ans[i].second);
            return 0;
        }
    }
}
