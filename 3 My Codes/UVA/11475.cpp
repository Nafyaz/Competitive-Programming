#include<bits/stdc++.h>
using namespace std;

string s;
int n, pal[200009];

void manacher()
{
    int i, l, r, k;

    for(i=0, l=0, r=-1; i < n; i++)
    {
        if(i > r)
            k = 1;
        else
            k = min(pal[l+r-i], r-i+1);

        while(i-k >= 0 && i+k < n && s[i-k] == s[i+k])
            k++;

        pal[i] = k;
        k--;

        if(i+k > r)
        {
            l = i-k;
            r = i+k;
        }
    }
}

int main()
{
    int i, center;
    string stemp;

    while(cin >> stemp)
    {
        s = "#";
        for(i = 0; i < stemp.size(); i++)
        {
            s.push_back(stemp[i]);
            s.push_back('#');
        }

        n = s.size();

        manacher();

        for(i = 0; i < n; i++)
        {
            if(s[i] != '#')
                cout << s[i];

            if(i + pal[i] == n)
            {
                center = i;
                break;
            }
        }

        for(i = center-1; i >= 0; i--)
        {
            if(s[i] != '#')
                cout << s[i];
        }

        cout << "\n";
    }
}
