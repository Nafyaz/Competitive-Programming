//Credit goes to pranto1209
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, l, r;
    cin>>n;
    int a[n], b[n];
    vector<int>v;
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
        v.push_back(a[i]-b[i]);
    }
    sort(v.begin(), v.end());
    l=0, r=n-1;
    long long cnt=0;
    while(l<r)
    {
        if(v[l]+v[r]>0)
        {
            cnt+=r-l;
            r--;
        }
        else
            l++;
    }
    cout<<cnt;
}
