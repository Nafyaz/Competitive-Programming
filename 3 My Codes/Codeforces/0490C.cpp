#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int a, b;
    cin >> s >> a >> b;

    int i, j;
    bool p1[1000009] = {0}, p2[1000009] = {0};

    int rem = 0, idx1 = INT_MAX, idx2 = -1;
    for(i = 0; i < s.size(); i++)
    {
        rem = (rem*10 + (s[i] - '0'))%a;
        if(rem == 0)
            p1[i] = 1;
        if(s[i] != '0')
            idx1 = min(idx1, i);
    }

    rem = 0, j = 1;
    for(i = s.size()-1; i >= 0; i--)
    {
        rem = ((s[i] - '0')*j + rem)%b;
        if(rem == 0)
            p2[i] = 1;
        if(s[i] != '0')
            idx2 = max(idx2, i);

        j = (j*10)%b;
    }

//    cout << idx1 << " " << idx2 << endl;
//    for(i = 0; i < s.size(); i++)
//        cout << s[i] << " " << p1[i] << " " << p2[i] << endl;

    for(i = 0; i < s.size() - 1; i++)
    {
        if(p1[i] && p2[i+1] && i >= idx1 && i+1 <= idx2)
        {
            cout << "YES\n";
            for(j = 0; j <= i; j++)
            {
                if(j >= idx1)
                    cout << s[j];
            }
            while(s[j] == '0')
            {
                cout << 0;
                j++;
            }
            cout << endl;

            for(; j < s.size(); j++)
                cout << s[j];

            cout << endl;
            return 0;
        }
    }

    cout << "NO";
}
