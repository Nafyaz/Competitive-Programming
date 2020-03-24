#include<bits/stdc++.h>
using namespace std;

int x[3];

void shuffle()
{

}

int main()
{
    map<string, int> mp;
    mp["C"] = 0;
    mp["C#"] = 1;
    mp["D"] = 2;
    mp["D#"] = 3;
    mp["E"] = 4;
    mp["F"] = 5;
    mp["F#"] = 6;
    mp["G"] = 7;
    mp["G#"] = 8;
    mp["A"] = 9;
    mp["B"] = 10;
    mp["H"] = 11;

    string a, b, c, s[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
    cin >> a >> b >> c;

    x[0] = mp[a], x[1] = mp[b], x[2] = mp[c];

    sort(x, x+3);

    do
    {
//        cout << x[0] << " " << x[1] << " " << x[2] << endl;
        if((x[1]-x[0]+12)%12 == 4 && (x[2]-x[1]+12)%12 == 3)
        {
            cout << "major" << endl;
            return 0;
        }

        else if((x[1]-x[0]+12)%12 == 3 && (x[2]-x[1]+12)%12 == 4)
        {
            cout << "minor" << endl;
            return 0;
        }
    }while(next_permutation(x, x+3));

    cout << "strange";

}
