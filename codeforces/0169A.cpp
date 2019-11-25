#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, i;
    cin >> n >> a >> b;

    int h[n];
    for(i = 0; i < n; i++)
        cin >> h[i];

    sort(h, h+n);
    cout << h[b] - h[b-1];
}
