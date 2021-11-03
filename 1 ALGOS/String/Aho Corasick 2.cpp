#include<bits/stdc++.h>
using namespace std;

const int sigma = 26; ///Alphabet Size
struct Vertex
{
    int next[sigma]; /// indices of child node
    bool leaf = false; /// if it is a last char
    int p = -1; /// index of parent node
    char pch; /// parent character
    int link = -1; /// suffix link for vertex
    int go[sigma]; /// save the values of go
    Vertex(int p=-1, char ch='$'): p(p), pch(ch)
    {
        fill(next, next+sigma, -1);
        fill(go, go+sigma, -1);
    }
};
vector<Vertex> t(1); ///Warning: multiple TCase
void add_string(string const& s)
{
    int v = 0;
    for (char ch : s)
    {
        int c = ch - 'a';
        if (t[v].next[c] == -1)
        {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}
int go(int v, char ch);
int get_link(int v)
{
    if (t[v].link == -1)
    {
        if (v == 0 || t[v].p == 0) t[v].link = 0;
        else t[v].link=go(get_link(t[v].p),t[v].pch);
    }
    return t[v].link;
}
///returns node to go from node 'v' with edge 'ch'
int go(int v, char ch)
{
    int c = ch - 'a';
    if (t[v].go[c] == -1)
    {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}
