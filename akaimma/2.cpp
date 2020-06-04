#include<bits/stdc++.h>
using namespace std;
#define a 100001
int arr[a]={0};

void sieve(){
    long int i,j;
    for(i=3;i*i<=a;i+=2){
        if(arr[i]){ for(j=i*2;j<=a;j+=i){
            arr[j]=i;
        }}
    }}

main()
{
    long int t,w,i,n,k;

    for(i=3;i<=a;i+=2){
        arr[i]=1;
    }
    sieve();

    for(i = 0; i < 20; i++)
    {
        cout << arr[i] << " ";
    }


    cin>>t;
    for(i=1;i<=t;i++){
        cin>>w;
        n=arr[w];
        k=w/n;
        if(!(k&1)){printf("Case %d: %d %d\n",i,n,k);}
        else printf("Case %d: Impossible\n");
    }
}
