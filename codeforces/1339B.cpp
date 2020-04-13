#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t, n, i, j, a[100009], mni, mnj, total;
    vector<ll> v;
    cin >> t;
    while(t--)
    {
        cin >> n;
        total = 0;
        for(i = 0; i < n; i++)
        {
            cin >> a[i];
            total += a[i];
        }

//        cout << total << endl;
        sort(a, a+n);

        for(i = 1; i < n; i++)
        {
            if(n*a[i] >= total)
            {
                mni = i-1;
                mnj = i;
                break;
            }
        }

        ll tempi = mni, tempj = mnj;
//        cout << diff << " " << mni << " " << mnj << endl;

        ll flag = 0;
        v.clear();
        while(mni >= 0 || mnj < n)
        {
            if(flag && mnj < n)
            {
                v.push_back(a[mnj]);
                mnj++;
                flag ^= 1;
            }
            else if(!flag && mni >= 0)
            {
                v.push_back(a[mni]);
                mni--;
                flag ^= 1;
            }
            else if(mni >= 0)
            {
                v.push_back(a[mni]);
                mni--;
                flag ^= 1;
            }
            else if(mnj < n)
            {
                v.push_back(a[mnj]);
                mnj++;
                flag ^= 1;
            }
        }
        flag = 1;
        for(i = 2; i < n; i++)
        {
            if(abs(v[i] - v[i-1]) < abs(v[i-1] - v[i-2]))
            {
                flag = 0;
                break;
            }
        }

        if(flag)
        {
            for(auto u : v)
                cout << u << " ";
            cout << endl;
            continue;
        }

        flag = 1;
        v.clear();
        mni = tempi;
        mnj = tempj;
        while(mni >= 0 || mnj < n)
        {
            if(flag && mnj < n)
            {
                v.push_back(a[mnj]);
                mnj++;
                flag ^= 1;
            }
            else if(!flag && mni >= 0)
            {
                v.push_back(a[mni]);
                mni--;
                flag ^= 1;
            }
            else if(mni >= 0)
            {
                v.push_back(a[mni]);
                mni--;
                flag ^= 1;
            }
            else if(mnj < n)
            {
                v.push_back(a[mnj]);
                mnj++;
                flag ^= 1;
            }

        }

        flag = 1;
        for(i = 2; i < n; i++)
        {
            if(abs(v[i] - v[i-1]) < abs(v[i-1] - v[i-2]))
            {
                flag = 0;
                break;
            }
        }

//        cout << "lol";
        if(flag)
        {
            for(auto u : v)
                cout << u << " ";
            cout << endl;
            continue;
        }
    }
}

/*
1
6
1 4 4 7 8 8
*/
