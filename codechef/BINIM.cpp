#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, parity[2], i, j, flag;
    string s, b[60];

    cin >> t;
    while(t--)
    {
        cin >> n >> s;

        parity[0] = parity[1] = 0;

        for(i = 0; i < n; i++)
            cin >> b[i];

//        flag = 1;
        while(1)
        {
            flag = 0;
            for(i = 0; i < n; i++)
            {
                if(b[i].size() && b[i][0] == '1' && s == "Dum")
                {
                    flag = 1;
                    s = "Dee";
                    for(j = 1; j < b[i].size(); j++)
                    {
                        if(b[i][j] == '1')
                        {

                            break;
                        }
                    }
                    b[i].erase(0, j);
                    break;
                }

                else if(b[i].size() && b[i][0] == '0' && s == "Dee")
                {
                    flag = 1;
                    s = "Dum";
                    for(j = 1; j < b[i].size(); j++)
                    {
                        if(b[i][j] == '0')
                        {

                            break;
                        }
                    }
                    b[i].erase(0, j);
                    break;
                }
            }
            if(!flag)
                break;
        }

        cout << (s == "Dum"? "Dee" : "Dum") << endl;

    }
}

