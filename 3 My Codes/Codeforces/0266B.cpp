#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, t, i;
    scanf("%d %d", &n, &t);
    string s;
    cin >> s;
    while(t--)
    {
        for(i = 0; i < n-1; i++)
        {
            if(s[i] == 'B' && s[i+1] == 'G')
            {
                swap(s[i], s[i+1]);
                i++;
            }
        }
    }
    cout << s;
}
