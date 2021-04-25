#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
    int t, caseno = 0, x, y, ans1, ans2, i;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;

        x = y = ans1 = 0;
        for(i = 0; i < (int)s.size(); i++)
        {
            if(s[i] == '^' && x && y)
            {
                x--;
                y--;
                ans1++;
            }
            else if(s[i] == '^')
            {
                x++;
            }
            else if(s[i] == '_' && x)
            {
                y++;
            }
        }

        x = y = ans2 = 0;
        for(i = (int)s.size() - 1; i >= 0; i--)
        {
            if(s[i] == '^' && x && y)
            {
                x--;
                y--;
                ans2++;
            }
            else if(s[i] == '^')
            {
                x++;
            }
            else if(s[i] == '_' && x)
            {
                y++;
            }
        }

//        if(ans1 != ans2)
//            cout << "6666666666666666666666666666666666666666666\n";

        cout << "Case " << ++caseno << ": " << max(ans1, ans2) << "\n";
    }
}
