#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i;

    cin >> n >> k;

    for(i = 0; n; i++)
        n /= k;

    cout << i;
}
