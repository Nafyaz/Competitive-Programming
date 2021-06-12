#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    while(cin >> s)
    {
        if(s == "#")
            break;

        bool possible = next_permutation(s.begin(), s.end());
        if(possible)
            cout << s << "\n";
        else
            cout << "No Successor\n";
    }

}
