#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int i, n, mxidx, lst;
    string s;

    vector<int> p(30), ans;

    while(getline(cin, s))
    {
        cout << s << "\n";

        stringstream ss;
        ss << s;

        i = 0;
        while(ss >> p[i])
        {
            i++;
        }
        n = i;

        ans.clear();
        for(lst = n; lst > 0; lst--)
        {


            mxidx = max_element(p.begin(), p.begin() + lst) - p.begin();
//            cout << mxidx << "  " << lst << "\n";
            if(mxidx == lst-1)
                continue;

            if(mxidx > 0)
            {
                reverse(p.begin(), p.begin()+mxidx+1);
//                cout << "Pancakes: ";
//                for(auto u : p)
//                    cout << u << " ";
//                cout << "\n";

                ans.push_back(n - mxidx);
            }

            reverse(p.begin(), p.begin()+lst);
//            cout << "Pancakes: ";
//            for(auto u : p)
//                cout << u << " ";
//            cout << "\n";

            ans.push_back(n - lst + 1);
        }

        ans.push_back(0);

        for(auto u : ans)
            cout << u << " ";
        cout << "\n";
     }
}
