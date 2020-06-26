#include<bits/stdc++.h>
using namespace std;

int main()
{
//    freopen("in.txt", "r", stdin);
    int t, i, flag;
    string n, l, r, n2;
    char x;
    cin >> t;
    while(t--)
    {
        cin >> n;
//        cout << n << ": ";
        flag = 1;
        for(i = 0; i < n.size(); i++)
        {
            if(n[i] != '9')
                flag = 0;
        }
        if(flag)
        {
            cout << '1' << string(n.size()-1, '0') << '1' << endl;
            continue;
        }

        flag = n.size()&1;
        l = n.substr(0, n.size()/2 + flag);
        r = l;
        reverse(r.begin(), r.end());
        if(flag)
            n2 = l + n[n.size()/2] + n.substr(n.size()/2+1, n.size()/2);
        else
            n2 = l + n.substr(n.size()/2, n.size()/2);

//        cout << n2;
        if(l+r > n2)
        {
            cout << l.substr(0, l.size()-flag) << r << endl;
            continue;
        }

        int idx;
        for(i = l.size() - 1; i >= 0; i--)
        {
            if(l[i] != '9')
            {
                idx = i;
                break;
            }
        }

        for(i = 0; i < l.size(); i++)
        {
            if(i == idx)
            {
                x = l[i];
                x++;
                l[i] = x;
            }
            else if(i > idx)
                l[i] = '0';
        }

        r = l;
        reverse(r.begin(), r.end());

        cout << l.substr(0, l.size()-flag) << r << endl;

    }
}

