#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s, x;
    while(cin >> s)
    {
        multiset<string> cube1, cube2;

        x = s[0] + s[5];
        cube1.insert(x);
        x = s[1] + s[4];
        cube1.insert(x);
        x = s[2] + s[3];
        cube1.insert(x);

        x = s[6] + s[11];
        cube2.insert(x);
        x = s[7] + s[10];
        cube2.insert(x);
        x = s[8] + s[9];
        cube2.insert(x);

        cout << (cube1 == cube2? "TRUE" : "FALSE") << "\n";
    }
}
