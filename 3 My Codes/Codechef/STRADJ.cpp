#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, x, y;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> n >> s;

        x = count(s.begin(), s.end(), '0');
        y = count(s.begin(), s.end(), '1');

        if(x > y)
            swap(x, y);

        if(!x)
            cout << "Bob\n";
        else if(x == 1)
            cout << "Alice\n";
        else if((x+y)%2 == 0)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }
}
