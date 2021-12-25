#include<bits/stdc++.h>
using namespace std;

string S;

bool func(string T)
{
    bool flag = 1;
    for(int i = 0; i < S.size() && flag; i++)
    {
        if(S[i] != T[i%3])
            flag = 0;
    }

    return flag;
}

int main()
{
    cin >> S;

    if(func("oxx") || func("xxo") || func("xox"))
        cout << "Yes";
    else
        cout << "No";
}
