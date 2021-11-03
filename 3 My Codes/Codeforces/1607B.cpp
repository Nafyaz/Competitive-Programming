#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long T, x, n, moves;

    cin >> T;

    while(T--)
    {
        cin >> x >> n;

        if(x&1)
        {
            moves = 1;

            if(n >= 1)
            {
                x += 1;
                n--;
            }

            moves = (n-1)/4*4;
            x += moves;
            n -= moves;

            moves += 2;
            while(n)
            {
                if(x&1)
                    x += moves;
                else
                    x -= moves;
                moves++;
                n--;
            }
        }
        else
        {
            moves = 1;

            if(n >= 1)
            {
                x -= 1;
                n--;
            }

            moves = (n-1)/4*4;
            x -= moves;
            n -= moves;

            moves += 2;
            while(n)
            {
                if(x&1)
                    x += moves;
                else
                    x -= moves;
                moves++;
                n--;
            }
        }

        cout << x << "\n";
    }
}
