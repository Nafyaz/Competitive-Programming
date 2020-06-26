#include<bits/stdc++.h>
using namespace std;

int conv(string s)
{
    return ((s[0] - '0')*10 + (s[1] - '0'))*60 + (s[3] - '0')*10 + (s[4] - '0');
}

int main()
{
    int t, caseno = 0;
    string swst, swed, smst, smed;
    int wst, wed, mst, med;
    cin >> t;
    while(t--)
    {
        cin >> swst >> swed >> smst >> smed;
        wst = conv(swst);
        wed = conv(swed);
        mst = conv(smst);
        med = conv(smed);

        if(mst > wed || med < wst)
            cout << "Case " << ++caseno << ": Hits Meeting" << endl;
        else
            cout << "Case " << ++caseno << ": Mrs Meeting" << endl;
    }
}

