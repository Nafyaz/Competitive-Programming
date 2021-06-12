#include<bits/stdc++.h>
using namespace std;

int Left[100009], Right[100009];

int main()
{
    int s, b, l, r, i;

    while(cin >> s >> b)
    {
        if(!s && !b)
            break;

        for(i = 1; i <= s; i++)
        {
            Left[i] = i-1;
            Right[i] = i+1;
        }

        Left[1] = -1;
        Right[s] = -1;

        while(b--)
        {
            cin >> l >> r;

            if(Left[l] != -1)
                cout << Left[l];
            else
                cout << "*";

            cout << " ";

            if(Right[r] != -1)
                cout << Right[r];
            else
                cout << "*";

            cout << "\n";

            Left[Right[r]] = Left[l];
            Right[Left[l]] = Right[r];
        }

        cout << "-\n";
    }
}
