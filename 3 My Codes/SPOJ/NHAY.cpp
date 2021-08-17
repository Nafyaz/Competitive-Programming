#include<bits/stdc++.h>
using namespace std;

int F[1000006];
string Z;

void KMP()
{
    int i, j;

    F[0] = 0;

    for(i = 1; i < Z.size(); i++)
    {
        j = F[i-1];

        while(j > 0 && Z[i] != Z[j])
            j = F[j-1];

        if(Z[i] == Z[j])
            j++;

        F[i] = j;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int i, n;
    string p, s;

    while(cin >> n >> p >> s)
    {
        Z = p + '#' + s;

        KMP();

//        for(i = 0; i < Z.size(); i++)
//            cout << Z[i] << " ";
//        cout << "\n";
//
//        for(i = 0; i < Z.size(); i++)
//            cout << F[i] << " ";
//        cout << "\n";

        for(i = p.size()+1; i < Z.size(); i++)
        {
            if(F[i] == p.size())
                cout << i - 2*p.size() << "\n";
        }

        cout << "\n";
    }
}
