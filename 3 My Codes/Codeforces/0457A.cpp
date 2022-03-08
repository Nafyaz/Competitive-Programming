#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll aVal[100005], bVal[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen("in.txt", "r", stdin);

    ll i, mn, flag;
    string a, b;

    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for(i = 0; i < a.size(); i++)
        aVal[i] = (a[i] == '1');
    for(i = 0; i < b.size(); i++)
        bVal[i] = (b[i] == '1');


    for(i = a.size() - 1; i >= 0; i--)
    {
        mn = min(aVal[i], aVal[i+1]);
        aVal[i+2] += mn;
        aVal[i+1] -= mn;
        aVal[i] -= mn;
    }
    for(i = b.size() - 1; i >= 0; i--)
    {
        mn = min(bVal[i], bVal[i+1]);
        bVal[i+2] += mn;
        bVal[i+1] -= mn;
        bVal[i] -= mn;
    }

//    for(i = 10; i >= 0; i--)
//        cout << aVal[i];
//    cout << "\n";
//    for(i = 10; i >= 0; i--)
//        cout << bVal[i];
//    cout << "\n";

    flag = 0;
    for(i = 0; i < 100005; i++)
    {
        mn = min(aVal[i], aVal[i+1]);
        aVal[i+2] += mn;
        aVal[i+1] -= mn;
        aVal[i] -= mn;

        mn = min(bVal[i], bVal[i+1]);
        bVal[i+2] += mn;
        bVal[i+1] -= mn;
        bVal[i] -= mn;

        if(aVal[i] && !bVal[i])
            flag = 1;
        else if(!aVal[i] && bVal[i])
            flag = -1;
    }

    if(flag == 0)
        cout << "=";
    else if(flag == 1)
        cout << ">";
    else
        cout << "<";
}
