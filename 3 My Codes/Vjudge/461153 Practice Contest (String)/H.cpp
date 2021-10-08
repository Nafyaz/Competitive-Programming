#include<bits/stdc++.h>
using namespace std;

int n;
string s = "#";
int pal[10000009], degree[5000009];

void manacher()
{
    int i, l, r, k;

    for(i=0, l=0, r=-1; i < n; i++)
    {
        if(i > r)
            k = 1;
        else
            k = min(pal[l+r-i], r-i+1);

        while(i-k >= 0 && i+k < n && s[i-k] == s[i+k])
            k++;

        pal[i] = k;
        k--;

        if(i+k > r)
        {
            l = i-k;
            r = i+k;
        }
    }
}

bool isPalindrome(int i, int j)
{
    int mid = (i+j)/2;
    return pal[mid] >= j-mid+1;
}

int findDegree(int i)
{
    if(i == 0)
        return degree[i] = 1;

    if(isPalindrome(1, 2*i+1))
    {
        return degree[i] = degree[(i+1)/2-1] + 1;
    }
    else
        return degree[i] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, ans = 0;
    string stemp;

    cin >> stemp;

    for(i = 0; i < stemp.size(); i++)
    {
        s.push_back(stemp[i]);
        s.push_back('#');
    }

    n = s.size();

    manacher();

    for(i = 0; i < stemp.size(); i++)
    {
        ans += findDegree(i);
    }

    cout << ans;
}

