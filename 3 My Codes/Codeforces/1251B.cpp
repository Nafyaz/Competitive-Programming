//antaji martasi pura

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q, n, i, j, o, z, len, flag;
    cin >> q;

    while(q--)
    {
        cin >> n;
        string s[n];

        flag = len = o = z = 0;

        for(i = 0; i < n; i++)
        {
            cin >> s[i];

            len += s[i].size();

            if(s[i].size() % 2 == 1)
                flag = 1;

            for(j = 0; j < s[i].size(); j++)
            {
                if(s[i][j] == '1')
                    o++;
                else
                    z++;
            }
        }

        if(len%2 == 1 || (len%2 == 0 && o%2 == 0))
            cout << n << endl;
        else if(!flag)
            cout << n-1 << endl;
        else
            cout << n << endl;
    }
}
