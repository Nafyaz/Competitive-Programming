#include<bits/stdc++.h>
using namespace std;

int pal[300009], n;
string s = "#";

void manacher()
{
    int i, l, r, k;

    for(i = 0, l = 0, r = -1; i < n; i++)
    {
        if(i > r)
            k = 1;
        else
            k = min(pal[l + r - i], r - i + 1);

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
    int i, ans = 0;
    string stemp;

    cin >> n >> stemp;

    for(i = 0; i < stemp.size(); i++)
    {
        s.push_back(stemp[i]);
        s.push_back('#');
    }

    n = s.size();

    manacher();

    for(i = 0; i < n; i++)
        cout << pal[i] << " ";
}
