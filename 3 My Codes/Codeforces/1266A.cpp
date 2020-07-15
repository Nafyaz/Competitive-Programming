#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, sum, even, zero;
    string s;

    cin >> n;
    while(n--)
    {
        cin >> s;
        zero = even = sum = 0;
        for(i = 0; i < s.size(); i++)
        {
            sum += s[i] - '0';
            if((s[i] - '0') % 2 == 0)
                even++;
            if(s[i] == '0')
                zero++;
        }

        if(sum % 3 == 0 && zero && even - 1)
            cout << "red\n";
        else
            cout << "cyan\n";
    }
}
