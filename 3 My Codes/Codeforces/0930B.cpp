#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second

vector<int> idx[26];

int main()
{
    int n, i, j, numerator, denominator;
    string s;

    cin >> s;

    n = s.size();

    for(i = 0; i < n; i++)
        idx[s[i] - 'a'].push_back(i);

    numerator = denominator = 0;
    for(i = 0; i < 26; i++)
    {
        if(idx[i].empty())
            continue;

        if(idx[i].size() == 1)
        {
            numerator++;
            denominator++;
            continue;
        }

        int maxSingle = 0;
        for(j = 1; j < n; j++)
        {
            map<char, int> freq;

            for(auto u : idx[i])
                freq[s[(u+j)%n]]++;

            int singleCnt = 0;
            for(auto u : freq)
            {
                if(u.ss == 1)
                    singleCnt++;
            }

            maxSingle = max(maxSingle, singleCnt);

//            cout << "i: " << i << "; j: " << j << "; singleCnt: " << singleCnt << "\n";
//            if(i == 0 && j == 4)
//            {
//                for(auto u : freq)
//                    cout << u.ff << " " << u.ss << "; ";
//                cout << "\n";
//            }
        }

        numerator += maxSingle;
        denominator += idx[i].size();
    }

    cout << fixed << setprecision(7) << (double)numerator / denominator;
}
