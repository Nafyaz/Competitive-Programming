#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, q, i, cnt = 0, pos;
    string s;
    char c;

    cin >> n >> q >> s;

    for(i = 0; i+2 < n; i++)
    {
        if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c')
            cnt++;
    }

    while(q--)
    {
        cin >> pos >> c;
        pos--;

        if(s[pos] == c)
        {
            cout << cnt << "\n";
            continue;
        }

        if(s[pos] == 'a' && pos+2 < n && s[pos+1] == 'b' && s[pos+2] == 'c')
            cnt--;
        if(s[pos] == 'b' && pos > 0 && s[pos-1] == 'a' && pos+1 < n && s[pos+1] == 'c')
            cnt--;
        if(s[pos] == 'c' && pos > 1 && s[pos-2] == 'a' && s[pos-1] == 'b')
            cnt--;

        if(c == 'a' && pos+2 < n && s[pos+1] == 'b' && s[pos+2] == 'c')
            cnt++;
        if(c == 'b' && pos > 0 && s[pos-1] == 'a' && pos+1 < n && s[pos+1] == 'c')
            cnt++;
        if(c == 'c' && pos > 1 && s[pos-2] == 'a' && s[pos-1] == 'b')
            cnt++;

        s[pos] = c;

        cout << cnt << "\n";
    }
}
