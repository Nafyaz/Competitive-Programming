#include<bits/stdc++.h>
using namespace std;

string operator+(string s2)
{
    s2.push_back('0');
    return s2;
}

int main()
{
    string s = "12345", t = "6789";

    t = s + t;

    cout << s << "  " << t;
}
