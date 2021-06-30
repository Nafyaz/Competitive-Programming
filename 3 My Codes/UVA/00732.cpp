#include<bits/stdc++.h>
using namespace std;

vector<string> v;
string s, t;

void func(string stkC, string stkI, int i, int j)
{
    if(j == t.size())
    {
        v.push(stkI);
        return;
    }
    else if(i == )


    if(stkC.empty())
        func(stkC + s[i], stkI + 'i', i+1, j);

}

int main()
{

    while(cin >> s)
    {
        cout << '[';

        func("", "", 0, 0);
    }
}
