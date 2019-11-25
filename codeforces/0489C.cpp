#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    int m, s, d, tm, ts;
    scanf("%d %d", &m, &s);

    tm = m;
    ts = s;
    while(tm)
    {
        d = 9;

        while(ts < d)
            d--;

        ts -= d;
        b.push_back(d + '0');
        tm--;
    }

    if(ts || (b[0] == '0' && b.size() > 1))
    {
        printf("-1 -1");
        return 0;
    }

    a = b;
    reverse(a.begin(), a.end());

    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != '0' && a[0] == '0')
        {
            a[0] = '1';
            a[i]--;
            break;
        }
    }

    cout << a << " " << b;

}
