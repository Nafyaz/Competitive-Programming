#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j;
    string s, mychar;
    map <char, int> mp;
    cin >> n >> m >> mychar;

    for(i = 0; i < n; i++)
        mp[mychar[i]] = i;

    string ch[n][17];


    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 17; j++)
        {
            cin >> s;
            ch[i][j] = s;
        }
    }

    int q = 0;
    while(m--)
    {
        string x[17];
        cin >> mychar;

        for(i = 0; i < 17; i++)
        {
            for(j = 0; j < 43; j++)
            {
                for(k = 0; k < mychar.size(); k++)
                {
                    int c = mp[mychar[k]];
                    if(ch[c][i][j] == '*')
                    {
                        x[i][j] = '*';
                        break;
                    }
                }
            }
        }


        for(k = 0; k < mychar.size(); k++)
        {
            int flag = 0, c = mp[mychar[k]];
            for(i = 0; i < 17; i++)
            {
                for(j = 0; j < 43; j++)
                {

                }
            }
        }


        cout << "Query " << ++q << ": ";



    }
}

