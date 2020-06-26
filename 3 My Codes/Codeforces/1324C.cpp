#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, i, n, a[200009], prev, mxdis;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        prev = mxdis = 0;

        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == 'R')
            {
                mxdis = max(mxdis, i+1-prev);
                prev = i+1;
            }
        }

        mxdis = max(mxdis, i+1-prev);

        cout << mxdis << endl;

    }
}
