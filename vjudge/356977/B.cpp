#include<bits/stdc++.h>
using namespace std;

int F[2000009], n;
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
    int t, caseno = 0;
    string a, b;
    cin >> t;
    while(t--)
    {
        cin >> b >> a;
        Z = a + '#' + b;

        KMP();

        int i, cnt = 0;

        for(i = a.size() + 1; i < Z.size(); i++)
        {
            if(F[i] == a.size())
                cnt++;
        }
        cout << "Case " << ++caseno << ": " << cnt << endl;
    }
}

