#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, i, res, pos, neg, mn;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        pos = neg = 0;
        res = mn = 0;
        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == '+')
                pos++;
            else
                neg++;
            if(mn > pos - neg)
            {
                mn = pos - neg;
                res += i+1;
            }
        }

        cout << s.size() + res << endl;
    }
}
