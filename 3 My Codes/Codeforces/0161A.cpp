#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, n, m, x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    int a[n], b[m];

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < m; i++)
        scanf("%d", &b[i]);

    vector <pair <int, int> > v;
    for(i = 0, j = 0; i < n && j < m;)
    {
        if(b[j] >= a[i] - x && b[j] <= a[i] + y)
        {
            v.push_back(make_pair(i+1, j+1));
            i++;
            j++;
        }
        else if(b[j] > a[i] + y)
            i++;
        else if(b[j] < a[i] - x)
            j++;
    }
    int len = v.size();
    printf("%d\n", len);
    for(i = 0; i < len; i++)
    {
        printf("%d %d\n", v[i].first, v[i].second);
    }
}
