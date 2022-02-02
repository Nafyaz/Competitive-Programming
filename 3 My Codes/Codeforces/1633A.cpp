#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n, i;

    cin >> T;

    while(T--)
    {
        cin >> n;

        if(n%7 == 0)
        {
            cout << n << "\n";
            continue;
        }

        n = n/10*10;

        for(i = 0; i <= 9; i++)
        {
            if((n+i)%7 == 0)
            {
                cout << n+i << "\n";
                break;
            }
        }
    }
}
