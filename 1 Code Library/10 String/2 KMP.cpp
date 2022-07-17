int LPS[MAXN], n;
string s;

void KMP()
{
    int i, j;
    n = s.size();

    LPS[0]=0;

    for (i = 1; i < n; i++)
    {
        j = LPS[i-1];

        while (j > 0 && s[i] != s[j])
            j = LPS[j-1];

        if (s[i] == s[j])
            j++;

        LPS[i] = j;
    }
}

int main()
{
    string p, t;
    cin >> p >> t;
    s = p + '#' + t;

    KMP();

    int i, cnt = 0;

    for(i = p.size() + 1; i < s.size(); i++)
    {
        if(LPS[i] == p.size())
            cnt++;
    }
    cout << cnt;
}
