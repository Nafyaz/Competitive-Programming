#include<iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int x, mx = 999, i, len = s.size();
    for(i = 0; i <= len - 3; i++)
    {
        x = abs(100*(s[i] - '0') + 10*(s[i+1] - '0') + s[i+2] - '0' - 753);
        mx = min(x, mx);
    }
    printf("%d", mx);
}
