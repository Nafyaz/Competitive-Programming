#include<bits/stdc++.h>
using namespace std;

int a[100], n;
void selection_sort()
{
    int i,j,min_index,temp;
    for(i=0;i<n;i++)
    {
        min_index=n-1;
        for(j=i;j<n;j++)
        {
            if(a[min_index]>a[j])
                min_index=j;
        }
        if(a[i]>a[min_index])
        {
            temp=a[min_index];
            a[min_index]=a[i];
            a[i]=temp;
        }
    }
}

int main()
{
    int i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];

    selection_sort();

    for(i = 0; i < n; i++)
        cout << a[i] << " ";
}