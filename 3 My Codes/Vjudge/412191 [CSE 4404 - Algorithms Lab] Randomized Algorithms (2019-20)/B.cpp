#include<bits/stdc++.h>
using namespace std;

int a[2000009], n;

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

        Qsort(l, j);
        Qsort(j+1, h);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i;

    while(1)
    {
        cin >> n;

        if(!n)
            break;

        for(i = 0; i < n; i++)
            cin >> a[i];

        Qsort(0, n);

        for(i = 0; i < n; i++)
            cout << a[i] << (i != n-1? " " : "");

        cout << endl;
    }
}
