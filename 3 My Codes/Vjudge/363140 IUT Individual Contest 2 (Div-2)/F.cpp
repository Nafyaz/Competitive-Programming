#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

int F[200009], n;
string Z;

void KMP()
{
    n = (int) Z.length();

    F[0]=0;

    for (int i=1; i<n; ++i) {

        int j = F[i-1];

        while (j > 0 && Z[i] != Z[j])

            j = F[j-1];

        if (Z[i] == Z[j])  ++j;

        F[i] = j;

    }
}

int main()
{
    string s, a, b;
    cin >> s >> a >> b;

    int i, afor, abk, bfor, bbk;
    afor = abk = bfor = bbk = -1;

    Z = a + '#' + s;
    KMP();
    for(i = a.size()+1; i < Z.size(); i++)
    {
        if(F[i] == a.size())
        {
            afor = i - 2*a.size();
            break;
        }
    }

    Z = b + '#' + s;
    KMP();
    for(i = b.size()+1; i < Z.size(); i++)
    {
        if(F[i] == b.size())
            bfor = i - 2*b.size();
    }

    reverse(s.begin(), s.end());

    Z = a + '#' + s;
    KMP();
    for(i = a.size()+1; i < Z.size(); i++)
    {
        if(F[i] == a.size())
        {
            abk = i - 2*a.size();
            break;
        }
    }

    Z = b + '#' + s;
    KMP();
    for(i = b.size()+1; i < Z.size(); i++)
    {
        if(F[i] == b.size())
            bbk = i - 2*b.size();

    }

//    cout << afor << " " << bfor << " " << abk << " " << bbk << endl;

    int p = 0, q = 0;
    if(afor != -1 && bfor != -1 && afor + a.size() <= bfor)
        p = 1;
    if(abk != -1 && bbk != -1 && abk + a.size() <= bbk)
        q = 1;

    if(p&&q)
        cout << "both";
    else if(p)
        cout << "forward";
    else if(q)
        cout << "backward";
    else
        cout << "fantasy";
}
