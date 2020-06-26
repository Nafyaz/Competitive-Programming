#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <pair <int, int> > pos, neg;
    int n, x, a, ans = 0, p;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &x, &a);
        if(x > 0)
            pos.push_back({x, a});
        else
            neg.push_back({-x, a});
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    if(pos.size() < neg.size())
        swap(pos, neg);

    for(p = 0; p != neg.size(); p++)
    {
        ans += pos[p].second;
        ans += neg[p].second;
    }
    if(p != pos.size())
        ans += pos[p].second;

    printf("%d", ans);
}
