#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q, freqa[26], freqb[26], found;

    string a, b;

    cin >> q;
    while(q--)
    {
        found = 0;
        memset(freqa, 0, sizeof(freqa));
        memset(freqb, 0, sizeof(freqb));

        cin >> a >> b;

        for(auto u : a)
            freqa[u - 'a']++;
        for(auto u : b)
            freqb[u - 'a']++;

        for(int i = 0; i < 26; i++)
        {
            if(freqa[i] && freqb[i])
            {
                found = 1;
                cout << "YES" << endl;
                break;
            }
        }

        if(!found)
            cout << "NO" << endl;

    }
}
