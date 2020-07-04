#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        int a[n];

        for(int i=0; i<n; i++)
        {
            cin>>a[i];

        }

        sort(a,a+n);

        int j=0;

        if(k>n)
        {
            int dif=k-n;

            while(dif--)
            {
                a[j]=a[j]*(-1);
                j++;
            }
        }

        j=0;

        while(n--)
        {
            a[j]=(-1)*a[j];
            j++;
        }


        int sum=0;

        for(int i=0; i<n; i++)
        {
            sum+=a[i];
        }

        cout<<sum<<endl;
    }
}
