#include<bits/stdc++.h>
using namespace std;

int a[100], n;

void insertion_sort()
{
    int i, j, key;
    for(i = 1; i < n; i++)
    {
        key = a[i];
        for(j = i; j > 0 && a[j-1] > key; j--)
            a[j] = a[j-1];
        a[j] = key;
    }
}

int main()
{
    int i;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];

    insertion_sort();

    for(i = 0; i < n; i++)
        cout << a[i] << " ";
}