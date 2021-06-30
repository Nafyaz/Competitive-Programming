#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, o, valid, valid_count = 0, cnt;
    string s = "iiiioooo";

    for(cnt = 0; ; cnt++)
    {
        valid = 1;
        i = o = 0;
        for(auto u : s)
        {
            if(u == 'i')
                i++;
            else
                o++;

            if(i < o)
                valid = 0;
        }

        if(valid)
        {
            cout << cnt << ": " << s << " (Valid)\n";
            valid_count++;
        }
        else
            cout << cnt << ": " << s << " (Invalid)\n";

        if(next_permutation(s.begin(), s.end()) == 0)
            break;
    }

    cout << "Total Valid Count: " << valid_count;
}
