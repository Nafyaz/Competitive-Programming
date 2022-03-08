#include<bits/stdc++.h>
using namespace std;

int main()
{
    int primes[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int i, yesCnt = 0, squareCnt = 0;
    string s;

    for(i = 0; i < 15; i++)
    {
        cout << primes[i] << "\n";
        cin >> s;
        if(s == "yes")
            yesCnt ++;
    }

    if(yesCnt == 0)
        cout << "prime\n";
    else if(yesCnt >= 2)
        cout << "composite\n";
    else
    {
        for(i = 0; i < 4; i++)
        {
            cout << primes[i]*primes[i] << "\n";
            cin >> s;
            if(s == "yes")
                squareCnt ++;
        }

        if(squareCnt)
            cout << "composite\n";
        else
            cout << "prime\n";
    }
}
