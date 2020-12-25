#include<bits/stdc++.h>
using namespace std;

string func(string s)
{
    string ret = "";

    for(auto u : s)
        ret = ret + (char)tolower(u);
    sort(ret.begin(), ret.end());

    return ret;
}

int main()
{
    cout << func("ladder");
}
