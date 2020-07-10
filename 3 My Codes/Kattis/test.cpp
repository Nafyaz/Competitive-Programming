#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    int b1, b2, dec = 0;
    cin >> s >> b1 >> b2; //123AB34    17    25
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
            dec = b1*dec + (s[i] - '0');
        else
            dec = b1*dec + (s[i] - 'A' + 10);
    }

    cout << dec;
}
