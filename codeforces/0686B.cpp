#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j;
    scanf("%d", &n);
    int a[n];
    vector <pair<int, int> > v;
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = n - 1; i >= 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            if(a[j] <= a[j+1])
                continue;
            swap(a[j], a[j+1]);
            v.push_back({j+1, j+2});
        }
    }

    for(auto u : v)
        cout << u.first << " " << u.second << endl;
}
