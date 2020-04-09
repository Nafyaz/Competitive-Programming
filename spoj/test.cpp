#include<bits/stdc++.h>
using namespace std;

long long a[100005],b[100005],sum1[100005] ,sum2[100005];

main()
{
    int t;
    cin >> t;
    while(t--)
    {
        //a[100005]={},b[100005]={},sum1[100005]={},sum2[100005]={};
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(sum1, 0, sizeof sum1);
        memset(sum2, 0, sizeof sum2);
        long long n,mew=1;
        cout << sum1[0] << endl;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if(a[i]==1)
            {
                sum1[i]++;
                cout << "hello" << endl;
                if(i)sum2[i]=sum2[i-1];
            }
            else if(a[i]==(-1))
            {
                sum2[i]--;
                if(i)sum1[i]=sum1[i-1];
            }
            else
            {
                if(i)sum2[i]=sum2[i-1];
                if(i)sum1[i]=sum1[i-1];
            }
            cout << "*" << i << " " <<sum1[i] << endl;
        }
        for(int i=0;i<n;i++)
        {
            cin >> b[i];
            if(i>0 && mew==1)
            {
                if(b[i]>0 && b[i]!=a[i])
                {
                    if(sum1[i-1]>0)mew=1;
                    else mew=0;
                    cout << "*" << sum1[i-1] << endl;
                }
                else if(b[i]<0 && b[i] !=a[i])
                {
                    if(sum2[i-1]<0)mew=1;
                    else mew=0;
                }
                else if(b[i]==0 && b[i]!=a[i])
                {
                    if(sum1[i-1]>0 && sum2[i-1]<0 )mew=1;
                    else mew=0;
                }
            }
            else
            {
                if(a[i]!=b[i])mew=0;
            }
        }
        //cout << mew<<endl;
        if(mew)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
