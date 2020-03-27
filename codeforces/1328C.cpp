#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, j, flag;
    string s, ans[2];
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        ans[0] = ans[1] = "";
        flag = -1;
        for(i = 0; i < n; i++)
        {
            if(flag == -1)
            {
                if(s[i] == '2')
                {
                    ans[0] = ans[0] + '1';
                    ans[1] = ans[1] + '1';
                }
                else if(s[i] == '0')
                {
                    ans[0] = ans[0] + '0';
                    ans[1] = ans[1] + '0';
                }
                else
                {
                    ans[0] = ans[0] + '1';
                    ans[1] = ans[1] + '0';
                    flag = 0;
                }
            }

            else
            {
                ans[0] = ans[0] + '0';
                ans[1] = ans[1] + s[i];
            }

        }

        cout << ans[0] << endl << ans[1] << endl;
    }
}
