int main()
{
    int T;

    cin>>T;

    while(T--)
    {
        string s;

        cin>>s;

        for(int i=0;i+1<s.size();i++)
        {
            if(s[i]==s[i+1])
            {
                s[i]='-';
                s[i+1]='-';
            }
        }
        set<char> st;

        for(auto u:s)
        {
            if(u!='-')
            {
                st.insert(u);
            }
        }

        for(auto u:st)
        {
            cout<<u;
        }

        cout<<"\n";





    }


}
