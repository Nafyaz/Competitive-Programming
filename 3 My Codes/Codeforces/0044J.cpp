#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, i, j;

    string board[1009];

    cin >> n >> m;

    for(i = 0; i < n; i++)
        cin >> board[i];

    if(n < 3 && m < 3)
    {
        cout << "NO";
        return 0;
    }

    set<char> c;
    char bc;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(j+2 < m && board[i][j] == 'w' && board[i][j+1] == 'b' && board[i][j+2] == 'w')
            {
                c.clear();
                if(i > 0)
                {
                    c.insert(board[i-1][j]);
                    c.insert(board[i-1][j+1]);
                    c.insert(board[i-1][j+2]);
                }
                if(i+1 < n)
                {
                    c.insert(board[i+1][j]);
                    c.insert(board[i+1][j+1]);
                    c.insert(board[i+1][j+2]);
                }
                if(j > 0)
                    c.insert(board[i][j-1]);
                if(j+3 < m)
                    c.insert(board[i][j+3]);

                bc = 'p';
                while(c.find(bc) != c.end())
                    bc++;

                if(bc == 't')
                {
                    cout << "NO";
                    return 0;
                }

                board[i][j] = board[i][j+1] = board[i][j+2] = bc;
            }

            else if(i+2 < n && board[i][j] == 'w' && board[i+1][j] == 'b' && board[i+2][j] == 'w')
            {
                c.clear();
                if(j > 0)
                {
                    c.insert(board[i][j-1]);
                    c.insert(board[i+1][j-1]);
                    c.insert(board[i+2][j-1]);
                }
                if(j+1 < m)
                {
                    c.insert(board[i][j+1]);
                    c.insert(board[i+1][j+1]);
                    c.insert(board[i+2][j+1]);
                }
                if(i > 0)
                    c.insert(board[i-1][j]);
                if(i+3 < n)
                    c.insert(board[i+3][j]);

                bc = 'p';
                while(c.find(bc) != c.end())
                    bc++;

                if(bc == 't')
                {
                    cout << "NO";
                    return 0;
                }

                board[i][j] = board[i+1][j] = board[i+2][j] = bc;
            }


//            if(i == 2 && j == 3)
//            {
//                for(auto u : c)
//                        cout << u << " ";
//                cout << "\n";
//                for(int k = 0; k < n; k++)
//                    cout << board[k] << "\n";
//                cout << "\n";
//            }
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(board[i][j] == 'w' || board[i][j] == 'b')
            {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES\n";
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            if(board[i][j] != '.')
                board[i][j] = board[i][j] - 'p' + 'a';
    }

    for(i = 0; i < n; i++)
        cout << board[i] << "\n";
}
