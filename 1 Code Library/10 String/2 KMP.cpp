// Longest Prefix which is also a Suffix
LL LPS[MAXN], n;

void KMP(string s)
{
    LL i, j, n = s.size();

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
