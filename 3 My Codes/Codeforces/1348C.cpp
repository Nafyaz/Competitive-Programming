#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, k, i;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cin >> s;
        sort(s.begin(), s.end());
        if(s[0] < s[k-1])
        {
            cout << s[k-1] << endl;
            continue;
        }

        map<char, int> freq;
        set<char> st;
        for(i = 0; i < n; i++)
        {
            freq[s[i]]++;
            st.insert(s[i]);
        }

        if(st.size() == 1)
        {
            cout << string((n+k-1)/k, s[0]) << endl;
            continue;
        }
        else if(st.size() == 2)
        {
            if(freq[s[0]] == k)
            {
                for(i = 0; i < n; i++)
                {
                    if(i%k == 0)
                        cout << s[i];
                }

                cout << endl;
                continue;
            }
            else
            {
                cout << s[0];
                for(i = k; i < n; i++)
                    cout << s[i];
                cout << endl;
                continue;
            }
        }

        else
        {
            for(i = k-1; i < n; i++)
                cout << s[i];
            cout << endl;
        }
    }
}
/*
8
4 2
baba
5 2
baacb
5 3
baacb
5 3
aaaaa
6 4
aaxxzz
7 1
phoenix
9 3
bbbbbcccc
5 3
aaabb
*/
