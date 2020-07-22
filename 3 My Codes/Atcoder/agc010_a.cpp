#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, a, o = 0;
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a;
        if(a&1)
            o++;
    }

    cout << (o%2 == 0? "YES" : "NO");
}
