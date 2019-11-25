#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j;
    scanf("%d", &n);
    int a[n];

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    set<pair <int, int>> s;

    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
            s.insert({a[i], a[j]});
    }
    printf("%d", s.size());
}
