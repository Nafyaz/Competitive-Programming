#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, i, st, en;
    cin >> t;
    char temp;
    string s, res;

    while(t--)
    {
         cin >> s;
         res = "";

        temp = s[0];
        st = en = 0;

        for(i = 1; i < s.size(); i++)
        {
            if(s[i] == temp)
                en++;
            else
            {
                if((en - st + 1) % 2 == 1 && res.find(temp) == string::npos)
                    res.push_back(temp);

                temp = s[i];
                st = en = i;
            }
        }

        if((en - st + 1) % 2 == 1 && res.find(temp) == string::npos)
            res.push_back(temp);

        sort(res.begin(), res.end());
        cout << res << endl;
    }

}
