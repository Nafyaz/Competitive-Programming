#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i;
    string s;
    vector<int> indices;

    cin >> s;

    if(s[0] == '@' || s.back() == '@')
    {
        cout << "No solution";
        return 0;
    }

    for(i = 1; i < s.size(); i++)
    {
        if(s[i] == '@')
            indices.push_back(i);
    }

    if(indices.size() == 0)
    {
        cout << "No solution";
        return 0;
    }
    else if(indices.size() == 1)
    {
        cout << s;
        return 0;
    }

    for(i = 1; i < indices.size(); i++)
    {
        if(indices[i] - indices[i-1] <= 2)
        {
            cout << "No solution";
            return 0;
        }
    }

    for(i = 0; i < s.size(); i++)
    {
        cout << s[i];
        if(i >= 2 && s[i-1] == '@' && indices.back() != i-1)
            cout << ',';
    }
}
