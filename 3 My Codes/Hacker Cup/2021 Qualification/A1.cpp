#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("A1_input.txt", "r", stdin);
    freopen("A1_output.txt", "w", stdout);

    int t, caseno = 0;

    string s;

    cin >> t;

    while(t--)
    {
        cin >> s;

        char vmax = 'A', cmax = 'B';
        int vmaxval = 0, cmaxval = 0, vtotal = 0, ctotal = 0;
        map<char, int> vfreq, cfreq;

        for(auto u : s)
        {
            if(u == 'A' || u == 'E' || u == 'I' || u == 'O' || u == 'U')
            {
                vfreq[u]++;
                vtotal++;
                if(vmaxval < vfreq[u])
                {
                    vmaxval = vfreq[u];
                    vmax = u;
                }
            }
            else
            {
                cfreq[u]++;
                ctotal++;
                if(cmaxval < cfreq[u])
                {
                    cmaxval = cfreq[u];
                    cmax = u;
                }
            }
        }

        cout << "Case #" << ++caseno << ": " << min((vtotal - vmaxval)*2 + ctotal, (ctotal - cmaxval)*2 + vtotal) << "\n";
    }
}
