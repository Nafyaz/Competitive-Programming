#include<bits/stdc++.h>
using namespace std;

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

    string p, t;
    cin >> p >> t;
    Z = p + '#' + t;

    KMP);

    int i, cnt = 0;

    for(i = p.size() + 1; i < Z.size(); i++)
    {
        if(F[i] == p.size())
            cnt++;
    }
    cout << cnt;
}
