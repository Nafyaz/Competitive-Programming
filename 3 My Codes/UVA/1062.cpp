#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, a[1009], prev, cnt, caseno = 0;
    string s;

    while(cin >> s)
    {
        if(s == "end")
            break;

        memset(a, 0, sizeof a);

        cnt = 0;

        for(i = 0; i < 26 && cnt < s.size(); i++)
        {
            prev = 30;
            for(j = 0; j < s.size(); j++)
            {
                if(s[j]-'A' <= prev && a[j] == 0)
                {
                    prev = s[j] - 'A';
                    a[j] = 1;
                    cnt++;
                }
            }
        }

        cout << "Case " << ++caseno << ": " << i << "\n";
    }
}
