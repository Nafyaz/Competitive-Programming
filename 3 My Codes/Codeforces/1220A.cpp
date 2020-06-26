#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, one = 0, zero = 0;
    string s;
    cin >> n >> s;

    for(i = 0; i < n; i++)
    {
        if(s[i] == 'n')
            one++;
    }

    zero = (n - 3*one)/4;

    while(one--)
        cout << "1 ";
    while(zero--)
        cout << "0 ";
}
