#include<bits/stdc++.h>
using namespace std;
int n,i,j,t,ans,a[2008],c[2008];
map<int,int> m;
bitset<2000> b;
int main()
{
    for(scanf("%d",&n); i<n; scanf("%d",a+i),m.find(a[i])==m.end()?m[a[i]]=t++:0,a[i]=m[a[i]],++i);
    for(ans=i=n; i--;)
    {
        for(j=n; j--; b[a[j]]=1<++c[a[j]]);
        for(b.any()?0:ans=0,j=i+1; j--; b[a[j]]=1<--c[a[j]],b.any()?0:ans=min(ans,i-j+1));
        for(j=t; j--; b[j]=c[j]=0);
    }
    printf("%d\n",ans),exit(0);
}
