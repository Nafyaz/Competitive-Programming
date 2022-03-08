#include<bits//stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, t, i, dot, st, ed;
    string s;

    cin >> n >> t >> s;

    dot = s.find('.');

    st = -1;
    for(i = dot+1; i < n; i++)
    {
        if(s[i] >= '5')
        {
            st = i;
            break;
        }
    }

    if(st == -1)
    {
        cout << s;
        return 0;
    }

    ed = n;
    for(i = st-1; i > dot && t > 0; i--, t--)
    {
        if(s[i+1] >= '5')
        {
            s[i]++;
            ed = i+1;
        }
    }

    if(!t || s[dot+1] < '5')
    {
        for(i = 0; i < ed; i++)
            cout << s[i];
        return 0;
    }

    ed = dot-1;
    for(i = dot-1; i >= 0 && s[i] == '9'; i--)
    {
        s[i] = '0';
        ed = i-1;
    }

    if(ed == -1)
    {
        cout << 1;
        for(i = 0; i < dot; i++)
            cout << s[i];
    }
    else
    {
        for(i = 0; i < ed; i++)
            cout << s[i];
        cout << (char)(s[ed]+1);
        for(i = ed+1; i < dot; i++)
            cout << s[i];
    }
}
