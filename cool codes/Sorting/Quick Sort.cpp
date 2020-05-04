#include<bits/stdc++.h>
using namespace std;

int a[100], n;

int Partition(int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;

    do
    {
        i++;
    }while(a[i] <= pivot);

    do
    {
        j--;
    }while(a[j] > pivot);

    if(i < j)
        swap(a[i], a[j]);

    return j;
}

void Qsort(int l, int h)
{
    if(l < h)
    {
        int j = Partition(l, h)
        Qsort(l, j);
        Qsort(j+1, h);
    }
}

int main()
{
    int i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];

    Qsort(0, n);

    for(i = 0; i < n; i++)
        cout << a[i] << " ";
}
