vector<int> z_function(string s)
{
    int i, l, r, n = s.size();
    vector<int> Z(n);
    Z[0] = 0;
    for(i = 1, l = 0, r = 0; i < n; i++)
    {
        if(i <= r) //This condition is false when i=1
            Z[i] = min(r-i+1, Z[i-l]);
        while(i+Z[i] < n && s[Z[i]] == s[i+Z[i]])
            Z[i]++; //if Z[1] has previous value, it will cause problem here

        if(i+Z[i] - 1 > r)
        {
            l = i;
            r = i+Z[i]-1;
        }
    }

    return Z;
}