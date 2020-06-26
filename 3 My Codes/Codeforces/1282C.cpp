#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define ll long long
#define ff first
#define ss second

int main()
{
    int m, n, T, a, b, i, j;
    vector<pair<int, int> > prob(200009);
    vector<int> easy, hard;
    cin >> m;
    while(m--)
    {
        cin >> n >> T >> a >> b;


        for(i = 0; i < n; i++)
            cin >> prob[i].ss;
        for(i = 0; i < n; i++)
            cin >> prob[i].ff;

        sort(prob.begin(), prob.end());

//        prob[0].ss = (prob[0].ss? b : a);
//        j = 0;
//        for(i = 1; i < n; i++)
//        {
//            if(prob[i].ff == prob[j].ff)
//                prob[j].ss += (prob[i].ss? b: a);
//            else
//            {
//                prob[j].ff = prob[i].ff;
//                j++;
//            }
//        }
        easy.clear();
        hard.clear();
        for(i = 0; i < n; i++)
        {
            if(prob[i].ss)
                hard.push_back(prob[i].ff);
            else
                easy.push_back(prob[i].ff);
        }

        sort(easy.begin(), easy.end());
        sort(hard.begin(), hard.end());

        int solved = 0, req = 0, i = 0, j = 0;
        while(i < easy.size() || j < hard.size())
        {
            while(i < easy.size() && req + easy[i] < hard[j])
            {
                req += easy[i];
                i++;
            }
        }

        cout << solved << endl;
    }
}
