#include<bits/stdc++.h>
using namespace std;

string add(string a, string b)
{
    int carry = 0, alen = a.size() - 1, blen = b.size() - 1;

    string x;
    int temp;
    while(alen >= 0 || blen >= 0)
    {
        if(alen < 0)
            temp = carry + b[blen] - '0';
        else if(blen < 0)
            temp = carry + a[alen] - '0';
        else
            temp = carry + a[alen] - '0' + b[blen] - '0';

        x.push_back(temp%10 + '0');
        carry = temp/10;

        alen--;
        blen--;
    }
    if(carry)
        x.push_back(carry + '0');
    reverse(x.begin(), x.end());
    //cout << a << " " << b << " " << x << endl;
    return x;
}

bool cmp(string a, string b)
{
    if(a.size() < b.size())
        return 1;
    else if(a.size() > b.size())
        return 0;
    else
        return a < b;
}

int main()
{
    int i, len, temp = 0;
    string s, t1, t2, ans, x;

    scanf("%d", &len);
    cin >> s;

    int mid = len/2;
    for(i = mid; i < len; i++)
    {
        t1 = s.substr(0, i);
        t2 = s.substr(i, len - i);
        if(t2[0] == '0')
            continue;

        x = add(t1, t2);
        if(ans.size() == 0 || cmp(x, ans))
            ans = x;
        temp++;
        if(temp > 1)
            break;
    }
    temp = 0;
    for(i = mid; i > 0; i--)
    {
        t1 = s.substr(0, i);
        t2 = s.substr(i, len - i);
        if(t2[0] == '0')
            continue;

        x = add(t1, t2);
        if(ans.size() == 0 || cmp(x, ans))
            ans = x;
        temp++;
        if(temp > 1)
            break;
    }

    cout << ans;
}
