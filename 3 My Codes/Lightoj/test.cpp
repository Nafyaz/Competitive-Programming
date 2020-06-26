#include<bits/stdc++.h>
using namespace std;
int freq[100005];
int pr[100005];
int diff[100005];
int main()
{
    int n, i;
    scanf("%d", &n);
    int a[n+1];
    for(i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        freq[a[i]]++;
        if(freq[a[i]]>1)
        {
            int temp=i-pr[a[i]];
            if((diff[a[i]]==0) || (diff[a[i]]==temp))
                diff[a[i]]=temp;
            else
                freq[a[i]]=-5;
        }
        pr[a[i]]=i;
    }
    vector <pair <int,int> > ans;
    ans.reserve(n+5);
    for(i=1; i<=n; i++)
        if(freq[a[i]]>0)
        {
            ans.push_back(make_pair(a[i], diff[a[i]]));
            freq[a[i]]=-5;
        }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(i=0; i<ans.size(); i++)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}
