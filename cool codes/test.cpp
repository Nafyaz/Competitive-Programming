#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,a[10],b[10],c[10],p,j,take=0,capacity;
    cout << "Enter number of capacity & stuffies: ";
    cin >> capacity >> n;
    cout << "Enter amount in kg: ";
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << "Enter price per kg: ";
    for(i=0;i<n;i++)
    {
        cin >> b[i];
        c[i]=b[i];
    }
    sort(c,c+n);
    for(i=n-1;i>=0;i--)
    {
        //cout << c[i];
        for(p=0;p<n;p++)
        {
            if(c[i]==b[p])
            {
                for(j=1;j<=a[p];j++)
                {
                    if(capacity>0)
                    {
                        take=take+b[p];
                        capacity--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    cout << take;
    return 0;
}
