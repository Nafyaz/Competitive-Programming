#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, len;
    string s;
    vector<int> dots;

    cin >> s;

    for(i = 0; i < s.size(); i++)
    {
        if(s[i] == '.')
            dots.push_back(i);
    }

    if(dots.size() == 0 || dots[0] == 0 || dots[0] > 8 || dots.back()+1 == s.size() || s.size() - dots.back() > 4)
    {
        cout << "NO";
        return 0;
    }

    vector<string> v;

    for(i = 0, j = 0; i+1 < dots.size(); i++)
    {
        if(dots[i+1] - dots[i] < 3 || dots[i+1] - dots[i] > 12)
        {
            cout << "NO";
            return 0;
        }

        len = dots[i] - j + 1 + min(3, dots[i+1]-dots[i]-2);

        v.push_back(s.substr(j, len));
        j = j + len;
    }

    v.push_back(s.substr(j));

    cout << "YES\n";

    for(auto u : v)
        cout << u << "\n";
}
