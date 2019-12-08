#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int main()
{
    int n,sum=0,avg=0,cnt=0,a,b,c;
    cin>>n;
    int ar[n]={0};
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
        sum+=ar[i];
    }
    avg=sum/n;
    for(int i=0;i<n;i++)
        if(ar[i]!=avg)
            cnt++;

    if(cnt>2 || avg*n!=sum)
        cout<<"Unrecoverable configuration.";

    else if(cnt==0)
        cout<<"Exemplary pages.";
    else
    {
        for(int i=0;i<n;i++)
        {
            if(ar[i]<avg)
                a=i;
            if(ar[i]>avg)
                b=i;
        }
        printf("%d ml. from cup #%d to cup #%d.",ar[b]-avg,a+1,b+1);
    }
    return 0;
}
