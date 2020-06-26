#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, d, c = 0, pos = 0, x;
    scanf("%d %d", &n, &d);
    string s, temp;
    cin >> s;

    while(1)
    {
        temp = s.substr(pos, d+1);
        //cout << temp << endl;
        x = temp.rfind('1');
        if(x == 0)
        {
            printf("-1");
            return 0;
        }
        else
            pos += x;

        c++;
        if(pos == s.size() - 1)
                break;

    }
    printf("%d", c);
}
