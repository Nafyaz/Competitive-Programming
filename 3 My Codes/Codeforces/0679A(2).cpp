#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nums[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 49};
    int i, yesCnt = 0;
    string s;

    for(i = 0; i < 19; i++)
    {
        cout << nums[i] << "\n";
        cin >> s;

        yesCnt += (s == "yes");
    }

    cout << (yesCnt <= 1? "prime\n" : "composite\n");
}
