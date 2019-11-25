#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, ans = 0, len;
    string s;
    cin >> s;
    len = s.size();
    for(i = 0; i < len - 4;)
    {
        j = s.find("bear", i);

        if(j == -1)
            break;

        i = j+1;
        ans += j;
        ans += len - j - 3 ;
    }
    printf("%d", ans);
}
