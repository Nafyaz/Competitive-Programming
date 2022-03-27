#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t, p, f, cnts, cntw, s, w, mine, his, swords, wAxes, ans;

    cin >> t;

    while(t--)
    {
        cin >> p >> f;
        cin >> cnts >> cntw;
        cin >> s >> w;


        ans = 0;

        //mySword, hisSword, myAxe, hisAxe
        mine = his = 0;

        swords = min(p/s, cnts);
        cnts -= swords;
        p -= swords*s;
        mine += swords;

        swords = min(f/s, cnts);
        cnts -= swords;
        f -= swords*s;
        his += swords;

        wAxes = min(p/w, cntw);
        cntw -= wAxes;
        p -= wAxes;
        mine += wAxes;

        wAxes = min(f/w, cntw);
        cntw -= wAxes;
        f -= wAxes;
        his += wAxes;

        ans = max(ans, mine+his);

        //hisSword, mySword, hisAxe, myAxe
        mine = his = 0;

        swords = min(f/s, cnts);
        cnts -= swords;
        f -= swords*s;
        his += swords;

        swords = min(p/s, cnts);
        cnts -= swords;
        p -= swords*s;
        mine += swords;

        wAxes = min(f/w, cntw);
        cntw -= wAxes;
        f -= wAxes;
        his += wAxes;

        wAxes = min(p/w, cntw);
        cntw -= wAxes;
        p -= wAxes;
        mine += wAxes;

        ans = max(ans, mine+his);


        //myAxe, hisAxe, mySword, hisSword
        mine = his = 0;

        wAxes = min(p/w, cntw);
        cntw -= wAxes;
        p -= wAxes;
        mine += wAxes;

        wAxes = min(f/w, cntw);
        cntw -= wAxes;
        f -= wAxes;
        his += wAxes;

        swords = min(p/s, cnts);
        cnts -= swords;
        p -= swords*s;
        mine += swords;

        swords = min(f/s, cnts);
        cnts -= swords;
        f -= swords*s;
        his += swords;

        ans = max(ans, mine+his);

        //hisAxe, myAxe, hisSword, mySword
        mine = his = 0;

        wAxes = min(f/w, cntw);
        cntw -= wAxes;
        f -= wAxes;
        his += wAxes;

        wAxes = min(p/w, cntw);
        cntw -= wAxes;
        p -= wAxes;
        mine += wAxes;

        swords = min(f/s, cnts);
        cnts -= swords;
        f -= swords*s;
        his += swords;

        swords = min(p/s, cnts);
        cnts -= swords;
        p -= swords*s;
        mine += swords;

        ans = max(ans, mine+his);

        cout << ans << "\n";
    }
}
