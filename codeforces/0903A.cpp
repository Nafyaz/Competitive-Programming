#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, a[110] = {0}, x;
    for(i = 0; i <= 33; i++)
    {
        for(j = 0; j <= 14; j++)
        {
            if(3*i + 7*j > 100)
                break;
            a[3*i + 7*j] = 1;
        }
    }

    cin >> n;
    while(n--)
    {
        cin >> x;

        a[x] ? cout << "YES" : cout << "NO";
        cout << endl;
    }
}
