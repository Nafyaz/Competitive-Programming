#include<bits/stdc++.h>
using namespace std;

int a[100], n;

void bubble_sort()
{
    int i,j,temp,flag;

    for(i=n-2;i>=0;i--)
    {
        flag=0;
        for(j=0;j<=i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

int main()
{
    int i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];

    bubble_sort()

    for(i = 0; i < n; i++)
        cout << a[i] << " ";
}