#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s[2], ans = "Yes";

    cin >> s[0] >> s[1];

    if(s[0] == "#." && s[1] == ".#")
        ans = "No";
    else if(s[0] == ".#" && s[1] == "#.")
        ans = "No";

    cout << ans;
}
