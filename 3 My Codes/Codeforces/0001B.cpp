#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, i, p, numeric, type, row, column;
    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;

        numeric = 0;
        type = 0;
        for(i = 0; i < s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
                numeric++;
            else
                numeric = 0;

            if(numeric == 1)
                type++;
        }

        if(type == 1)
        {
            row = 0;
            column = 0;

            for(i = 0; i < s.size(); i++)
            {
                if(s[i] >= 'A' && s[i] <= 'Z')
                    column = column*26 + (s[i]-'A'+1);
                else
                    row = row*10 + (s[i] - '0');
            }

            cout << 'R' << row << 'C' << column;
        }
        else
        {
            row = 0;
            column = 0;

            for(i = 1; s[i] != 'C'; i++)
                row = row*10 + (s[i] - '0');
            for(i = i+1; i < s.size(); i++)
                column = column*10 + (s[i] - '0');

            for(i = 1, p = 26; column > p; i++, p *= 26)
                column -= p;

            column--;

            stack<char> stk;
            while(column)
            {
                stk.push((char)(column%26 + 'A'));
                column /= 26;
            }

            while(i>stk.size())
            {
                cout << 'A';
                i--;
            }
            while(!stk.empty())
            {
                cout << stk.top();
                stk.pop();
            }
            cout << row;
        }

        cout << "\n";
    }
}
