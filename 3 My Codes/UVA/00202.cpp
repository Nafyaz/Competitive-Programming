#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    int mark[3001], i;
    while(cin >> a >> b)
    {
        string s;
        memset(mark, -1, sizeof mark);
        cout << a << "/" << b << " = " << a/b << ".";

        for(i = 0; ; i++)
        {
            a = a%b;
            mark[a] = i;
            a = a*10;
            s = s + to_string(a/b);
            if(mark[a%b] != -1)
                break;
        }
        int st = mark[a%b], ed = i+1;

        for(i = 0; i < ed && i < 50; i++)
        {
            if(i == st)
                cout << "(";
            cout << s[i];
        }
        if(i < ed) printf("...");
        cout << ")\n";
        cout << "   " << ed-st << " = number of digits in repeating cycle\n\n";
    }
}
