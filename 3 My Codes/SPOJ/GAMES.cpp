#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, dot, score, match, g;
    string avg;

    cin >> t;

    while(t--)
    {
        cin >> avg;

        dot = avg.find('.');
        if(dot == -1)
        {
            cout << "1\n";
            continue;
        }

        score = 0;
        match = 1;
        for(i = dot+1; i < avg.size(); i++)
        {
            score *= 10;
            score += avg[i] - '0';

            match *= 10;
        }

        g = __gcd(score, match);
        cout << match/g << "\n";
    }
}
