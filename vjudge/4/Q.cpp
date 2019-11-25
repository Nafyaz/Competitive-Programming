#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, n, t, a, b;
    scanf("%d %d", &n, &t);
    vector <int> v;
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        if(b <= t)
            v.push_back(a);
    }
    if(!v.size())
    {
        printf("TLE");
        return 0;
    }
    sort(v.begin(), v.end());
    printf("%d", v[0]);
}
