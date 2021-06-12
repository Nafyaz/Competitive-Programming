#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("out.txt", "w", stdout);
    int i, h, u, d, f, hf, curr_h;

    while(cin >> h >> u >> d >> f)
    {
        if(!h)
            break;

        hf = u*f;
        h *= 100;
        u *= 100;
        d *= 100;

        curr_h = 0;

        for(i = 1; ; i++)
        {
//            cout << i << " " << curr_h << " ";

            curr_h += max(0, (u - hf*(i-1)));
            if(curr_h > h)
                break;

//            cout << u - hf*(i-1) << " " << curr_h << " ";

            curr_h -= d;

//            cout << curr_h << "\n";

            if(curr_h < 0)
                break;
        }

        if(curr_h < 0)
            cout << "failure on day " << i << "\n";
        else
            cout << "success on day " << i << "\n";
    }
}
