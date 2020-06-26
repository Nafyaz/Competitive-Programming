#include<bits/stdc++.h>
using namespace std;

string conv(int n)
{
    string ret;
    char c;
    while(n)
    {
        c = ('0' + n%4);
        ret = ret + c;
        n /= 4;
    }
    ret = ret + string(4-ret.size(), '0');
    reverse(ret.begin(), ret.end());

    return ret;
}

int main()
{
    int n = 63, i, j, ans[10009];
    bool a[10009] = {0};

    for(i = 1; i <= n; i++)
    {
        if(i%3 == 1)
        {
            for(j = 1; j <= n; j++)
            {
                if(!a[j])
                {
                    ans[i] = j;
                    break;
                }
            }
        }
        else if(i%3 == 2)
        {
            for(j = 1; j <= n; j++)
            {
                if(!a[j] && (j^ans[i-1]) != 0 && !a[j^ans[i-1]])
                {
                    ans[i] = j;
                    break;
                }
            }
        }
        else
            ans[i] = ans[i-1]^ans[i-2];
//        cout << i << " " << ans[i] << endl;
        a[ans[i]] = 1;
    }

    for(i = 1; i <= n; i++)
    {
        if(i%3 == 1)
            cout << setw(3) << i/3 << ": " << conv(ans[i]) << endl;
    }
    cout << endl;
    for(i = 1; i <= n; i++)
    {
        if(i%3 == 2)
            cout << setw(3) << i/3 << ": " << conv(ans[i]) << endl;
    }
    cout << endl;
    for(i = 1; i <= n; i++)
    {
        if(i%3 == 0)
            cout << setw(3) << i/3 << ": " << conv(ans[i]) << endl;
    }
    cout << endl;
}
/*
  1: 0001
  4: 0010
  7: 0011
 10: 0012
 13: 0013
 16: 0100
 19: 0101
 22: 0102
 25: 0103
 28: 0110
 31: 0111
 34: 0112
 37: 0113
 40: 0120
 43: 0121
 46: 0122
 49: 0123
 52: 0130
 55: 0131
 58: 0132
 61: 0133

  2: 0002
  5: 0020
  8: 0022
 11: 0023
 14: 0021
 17: 0200
 20: 0202
 23: 0203
 26: 0201
 29: 0220
 32: 0222
 35: 0223
 38: 0221
 41: 0230
 44: 0232
 47: 0233
 50: 0231
 53: 0210
 56: 0212
 59: 0213
 62: 0211

  3: 0003
  6: 0030
  9: 0033
 12: 0031
 15: 0032
 18: 0300
 21: 0303
 24: 0301
 27: 0302
 30: 0330
 33: 0333
 36: 0331
 39: 0332
 42: 0310
 45: 0313
 48: 0311
 51: 0312
 54: 0320
 57: 0323
 60: 0321
 63: 0322
*/
