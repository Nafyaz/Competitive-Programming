#include<bits/stdc++.h>
#include<regex>
using namespace std;
int main()
{
    int n, i;
    string x[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    string str;
    bool a;

    cin >> n >> str;
    if(n == 6)
        cout << "jolteon";
    else
    {
        regex e(str);
        for(i = 0; i < 8; i++)
        {
            if(regex_match(x[i], e))
                cout << x[i];
        }
    }
}
