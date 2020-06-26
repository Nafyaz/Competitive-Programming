#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second


int main()
{
    int i, j, n, I;
    scanf("%d %d", &n, &I);
    int a[n];
    I =
    I = min(31, I);
    int dis = 1 << I;

    map <int, int> mp;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        mp[a[i]]++;
    }

    int total = 0;
    vector <int> v;
    for(auto x : mp)
    {
        v.push_back(x.ss);
        total += x.ss;
    }

    i = 0;
    j = 0;
    int ans = 0, mxans = 0;;
    while(j < v.size())
    {
        ans = ans + v[j];
        if(j-i+1 > dis)
        {
            ans = ans - v[i];
            i++;
        }
//        if(j - i + 1 == min(n, dis))
//        {
//
//        }
        mxans = max(mxans, ans);
        j++;
    }

    printf("%d", total - mxans);
}
