#include<bits/stdc++.h>
using namespace std;

string operator+(string s2)
{
    s2.push_back('0');
    return s2;
}

int main()
{
    int x = -3;

    cout << (floor)((double)x/2);
}
