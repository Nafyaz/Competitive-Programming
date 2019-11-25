#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int main()
{
    int n, i;
    scanf("%d", &n);
    vector <pair<int, int> > v(n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &v[i].ff);
        v[i].ss = i;
    }

    sort(v.begin(), v.end(), greater<pair<int, int> >());

    int l = v[0].ss - 1;
    int h = v[0].ss + 1;

    for(i = 1; i < n; i++)
    {
        if(v[i].ss == l)
            l--;
        else if(v[i].ss == h)
            h++;
        else
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}
