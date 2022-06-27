#include<bits/stdc++.h>
using namespace std;

int a[100], n;

int Partition(int l, int h)
{
    int pivot = a[l];
    int i, j = h;

    for(i = h-1; i > l; i--)
    {
        if(a[i] > pivot)
        {
            j--;
            swap(a[i], a[j]);
        }
    }

    swap(a[l], a[j-1]);
    return j-1;
}

void Qsort(int l, int h)
{
    if(l+1 < h)
    {
        int j = Partition(l, h);
//        for(int i = 0; i < n; i++)
//            cout << a[i] << " ";
//        cout << endl;

        Qsort(l, j);
        cout << a[j] << " ";
        Qsort(j+1, h);
//        for(j = l; j < h; j++)
//            cout << a[j] << " ";
//        cout << endl;
    }
    else if(l+1 == h)
        cout << a[l] << " ";
}

int main()
{
    int i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];

    Qsort(0, n);

//    for(i = 0; i < n; i++)
//        cout << a[i] << " ";
}