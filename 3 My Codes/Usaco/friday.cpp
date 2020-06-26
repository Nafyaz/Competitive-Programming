/*
ID: nafis.f1
TASK: friday
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;

bool is_leap(int y)
{
    if(y%4 != 0)
        return 0;
    if(y%100 == 0 && y%400 != 0)
        return 0;
    return 1;
}

int main()
{
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int m[12], i, j, n;

    m[0] = 0;
    for(i = 1; i < 12; i++)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            m[i] = (m[i-1] + 31)%7;
        else if(i == 2)
            m[i] = m[i-1];
        else
            m[i] = (m[i-1] + 30)%7;
    }
//    for(i = 0; i < 12; i++)
//        cout << i << " " << m[i] << endl;

    cin >> n;
    int leapyear = 0, freq[7] = {0};
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 12; j++)
        {
            if(is_leap(1900 + i) && j == 2)
                leapyear++;
            freq[(m[j] + leapyear + i)%7]++;
        }
    }

//    cout << leapyear << endl;

    for(i = 0; i < 6; i++)
        cout << freq[i] << " ";
    cout << freq[6] << endl;
}
