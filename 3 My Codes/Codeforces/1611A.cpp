#include<bits/stdc++.h>
using namespace std;

bool isEven(char c)
{
    return (c == '2' || c == '4' || c == '6' || c == '8');
}

int main()
{
    int T;
    string n;

    cin >> T;

    while(T--)
    {
        cin >> n;

        if(isEven(n.back()))
            cout << "0\n";
        else if(isEven(n[0]))
            cout << "1\n";
        else if(n.find('2') != n.npos || n.find('4') != n.npos || n.find('6') != n.npos || n.find('8') != n.npos)
            cout << "2\n";
        else
            cout << "-1\n";
    }
}
