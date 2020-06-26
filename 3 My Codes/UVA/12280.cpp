#include<bits/stdc++.h>
using namespace std;

int alph[26];

int calc(char i)
{
    if(i < 'A' || i > 'Z')
        return 0;

    if(alph[i - 'A'])
        return alph[i - 'A'];

    int bin = i, ret = 0;

    while(bin)
    {
        if(bin&1)
            ret += 500;
        else
            ret += 250;
        bin = bin >> 1;
    }

    alph[i - 'A'] = ret;
    return ret;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int t, caseno = 0, i, left, right, lpos, rpos, temp;
    string s[8];

    cin >> t;
    while(t--)
    {
        for(i = 0; i < 8; i++)
            cin >> s[i];
        left = right = 0;
        queue <char> l, r;

        for(i = 0; i < 8; i++)
        {
            left += calc(s[3][i]);
            left += calc(s[4][i]);
            left += calc(s[5][i]);
            for(int j = 3; j <= 5; j++)
            {
                if(calc(s[j][i]))
                    l.push(s[j][i]);
            }
        }

        for(i = 10; i < 17; i++)
        {
            right += calc(s[3][i]);
            right += calc(s[4][i]);
            right += calc(s[5][i]);
            for(int j = 3; j <= 5; j++)
            {
                if(calc(s[j][i]))
                    r.push(s[j][i]);
            }
        }
        for(int j = 3; j <= 5; j++)
        {
            if(s[j][10] == '/')
                rpos = j;
            if(s[j][0] == '/')
                lpos = j;
        }

        cout << "Case " << ++caseno << ":" << endl;

//        while(!l.empty())
//        {
//            cout << l.front() << " ";
//            l.pop();
//        }
//        while(!r.empty())
//        {
//            cout << r.front() << " ";
//            r.pop();
//        }

        if(left == right)
        {
            if(lpos == rpos)
                cout << "The figure is correct." << endl;
            else
            {
                cout << "........||........\n";
                cout << ".../\\...||.../\\...\n";
                cout << "../..\\..||../..\\..\n";
                cout << "./....\\.||./....\\.\n";
                cout << "/";
                temp = l.size();
                while(!l.empty())
                {
                    cout << l.front();
                    l.pop();
                }
                for(i = 1; i <= 6 - temp; i++)
                    cout << '.';
                cout << "\\||/";
                temp = r.size();
                while(!r.empty())
                {
                    cout << r.front();
                    r.pop();
                }
                for(i = 1; i <= 6 - temp; i++)
                    cout << '.';
                cout << "\\\n";
                cout << "\\______/||\\______/\n";
                cout << "........||........\n";
            }
        }

        else if(left < right)
        {
            if(lpos < rpos)
                cout << "The figure is correct." << endl;
            else
            {
                cout << ".../\\...||........\n";
                cout << "../..\\..||........\n";
                cout << "./....\\.||.../\\...\n";
                cout << "/";
                temp = l.size();
                while(!l.empty())
                {
                    cout << l.front();
                    l.pop();
                }
                for(i = 1; i <= 6 - temp; i++)
                    cout << '.';
                cout << "\\||../..\\..\n";
                cout << "\\______/||./....\\.\n";
                cout << "........||/";
                temp = r.size();
                while(!r.empty())
                {
                    cout << r.front();
                    r.pop();
                }
                for(i = 1; i <= 6 - temp; i++)
                    cout << '.';
                cout << "\\\n";
                cout << "........||\\______/\n";
            }
        }

        else if(left > right)
        {
            if(lpos > rpos)
                cout << "The figure is correct." << endl;
            else
            {
                cout << "........||.../\\...\n";
                cout << "........||../..\\..\n";
                cout << ".../\\...||./....\\.\n";
                cout << "../..\\..||/";
                temp = r.size();
                while(!r.empty())
                {
                    cout << r.front();
                    r.pop();
                }
                for(i = 1; i <= 6 - temp; i++)
                    cout << '.';
                cout << "\\\n";
                cout << "./....\\.||\\______/\n";
                cout << "/";
                temp = l.size();
                while(!l.empty())
                {
                    cout << l.front();
                    l.pop();
                }
                for(i = 1; i <= 6 - temp; i++)
                    cout << '.';
                cout << "\\||........\n";
                cout << "\\______/||........\n";
            }
        }
    }
}

