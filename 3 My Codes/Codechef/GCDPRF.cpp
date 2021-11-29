#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, i, b[100005], flag;

    cin >> T;

    while(T--)
    {
        cin >> n;

        for(i = 0; i < n; i++)
            cin >> b[i];

        b[n] = 1;
        flag = 1;
        for(i = n-1; i >= 0; i--)
        {
            if(b[i] % b[i+1] != 0)
            {
                flag = 0;
                break;
            }
        }

        if(!flag)
        {
            cout << "-1\n";
            continue;
        }

        for(i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << "\n";
    }
}
