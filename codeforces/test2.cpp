    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    ll ara[100005];
    int dp1[100005];
    int dp2[100005];


    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n;
        cin>>n;
        int maxv=0;
        for(int i=1;i<=n;i++) cin>>ara[i];
        for(int i=1;i<=n;i++){
            if(ara[i]>ara[i-1]) dp1[i]=dp1[i-1]+1;
            else dp1[i]=1;
            if(i!=n) maxv=max(maxv,dp1[i]+1);
        }
        for(int i=n;i>=1;i--){
            if(ara[i]<ara[i+1]) dp2[i]=dp2[i+1]+1;
            else dp2[i]=1;
            if(i!=1) maxv=max(maxv,dp2[i]+1);
        }
        //for(int i=1;i<=n;i++) cout<<dp1[i]<<" ";
        //cout<<endl;
        //for(int i=1;i<=n;i++) cout<<dp2[i]<<" ";
        //cout<<endl;

        for(int i=1;i<=n;i++){
            if(ara[i+1]-ara[i-1]>=2LL) maxv=max(maxv,1+dp1[i-1]+dp2[i+1]);
        }
        if(n==1) maxv=1;
        cout<<maxv;
    }
