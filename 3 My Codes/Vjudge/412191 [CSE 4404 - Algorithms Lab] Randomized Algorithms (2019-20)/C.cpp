#include<bits/stdc++.h>
using namespace std;

int a[1009];

int Partition(int l, int h)
{
    int pivot = a[l + rand()%(h-l+1)], b[h-l+1];
    int i, mn = l, mx = h;

    for(i = l; i <= h; i++)
    {
        if(a[i] > pivot)
        {
            b[mx] = a[i];
            mx--;
        }
        else
        {
            b[mn] = a[i];
            mn++;
        }
    }

    for(i = l; i <= h; i++)
        a[i] = b[i];

    return mn;
}

void Qsort(int l, int h)
{
    if(l < h)
    {
        int j = Partition(l, h);

        Qsort(l, j-1);
        Qsort(j+1, h);
    }
}

int main()
{
    int n, i;
    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    srand(time(0));
    Qsort(0, n-1);

    for(i = 0; i < n; i++)
        cout << a[i] << " ";
}
