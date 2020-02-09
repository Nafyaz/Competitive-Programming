#include<iostream>
using namespace std;
int main()
{
  int t,i;
  cin>>t;
  for(i=0;i<t;i++)
  {
     int m,n,j,k,l,temp,x,y,d;
     cin>>n>>m;
     int a[n];
     for(j=0;j<n;j++)
     {
        cin>>a[j];
     }
     for(k=0;k<m;k++)
     {
        char s[2];
        cin>>s;
        if(s[0]=='S')
        {
           cin>>d;
           for(j=0;j<n;j++)
           {
             a[j]+=d;
           }
        }
        else if(s[0]=='M')
        {
           cin>>d;
           for(j=0;j<n;j++)
           {
             a[j]*=d;
           }
        }
        else if(s[0]=='D')
        {
           cin>>d;
           for(j=0;j<n;j++)
           {
             a[j]/=d;
           }
        }
        else if(s[0]=='R')
        {
           for(j=0,l=n-1;j<n/2;j++,l--)
           {
              temp=a[j];
              a[j]=a[l];
              a[l]=temp;
           }
        }
        else if(s[0]=='P')
        {
          cin>>x>>y;
          temp=a[x];
          a[x]=a[y];
          a[y]=temp;
        }
     }
     cout<<"Case "<<i+1<<endl;
     cout<<a[0];
     for(j=1;j<n;j++)
     {
       cout<<" "<<a[j];
     }
  }
  return 0;
}
