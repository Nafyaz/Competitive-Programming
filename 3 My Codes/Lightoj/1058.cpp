#include<bits/stdc++.h>
using namespace std;
stack <pair<int, int> > s;
vector <pair<int, int> > v;
int ans;
bool isPara(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4)
{
    if((y1 - y2) * (x3 - x4) == (x1 - x2) * (y3 - y4) || (y1 - y4) * (x2 - x3) == (y2 - y3) * (x1 - x4))
        return 1;
    return 0;
}

void gc(int i)
{
    if(s.size() == 4)
    {
        if(isPara(s[]))
    }
}
int main()
{
    int t, caseno = 0, n, i, x, y;
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &x, &y);
            v.push_back(make_pair(x, y));
        }
        gc(0);
    }
}
