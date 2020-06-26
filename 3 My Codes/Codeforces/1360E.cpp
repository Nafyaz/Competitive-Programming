#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, j, n, flag;
    string s[55];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        flag = 1;
        for(i = 0; i < n-1 && flag; i++)
        {
            for(j = 0; j < n-1 && flag; j++)
            {
                if(s[i][j] == '1' && s[i+1][j] == '0' && s[i][j+1] == '0')
                    flag = 0;
            }
        }

        cout << (flag? "YES\n" : "NO\n");
    }
}
