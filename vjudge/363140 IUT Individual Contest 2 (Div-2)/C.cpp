//very bad solution
#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool a[10000];

int main()
{
    ll i, j, n;
    cin >> n;

    for(i = 0, j = 0; i < 1000009; i++)
    {
        a[j] = 1;
        j = (j+i)%n;
    }

    for(i = 0; i < n; i++)
    {
        if(a[i] == 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES";
}

