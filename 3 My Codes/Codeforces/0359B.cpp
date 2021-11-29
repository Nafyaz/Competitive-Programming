#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, i;

    cin >> n >> k;

    for(i = 1; i <= n; i++)
    {
        if(k)
        {
            cout << 2*i << " " << 2*i-1 << " ";
            k--;
        }
        else
            cout << 2*i-1 << " " << 2*i << " ";
    }
}
