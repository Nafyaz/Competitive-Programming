#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, i, j, a, k, n, flag;
    cin >> t;
    while(t--)
    {
        cin >> n;
        flag = j = 0;
        for(i = 1; j + i < n; i++)
        {
            j += i;
            if((n-j)%(i+1) == 0)
            {
                flag = 1;
                cout << n << " = ";
                a = (n-j)/(i+1);
                cout << a;
                for(k = 1; k <= i; k++)
                    cout << " + " << a+k;
                break;
            }
        }

        if(!flag)
            cout << "IMPOSSIBLE";

        cout << endl;
    }
}
