#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, m;
    int i, L, R, D, U, row, col, str, stc;
    string s;

    cin >> T;

    while(T--)
    {
        cin >> n >> m >> s;

        L = R = D = U = 0;
        row = col = 0;
        str = stc = 0;

        for(i = 0; i < s.size(); i++)
        {
            if(s[i] == 'L')
                col--;
            if(s[i] == 'R')
                col++;
            if(s[i] == 'U')
                row--;
            if(s[i] == 'D')
                row++;

            L = min(L, col);
            R = max(R, col);
            U = min(U, row);
            D = max(D, row);

            if(R-L+1 > m || D-U+1 > n)
                break;

            str = abs(U);
            stc = abs(L);
        }

        cout << str+1 << " " << stc+1 << "\n";
    }
}
