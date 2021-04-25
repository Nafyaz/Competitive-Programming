double polygonDiameter(vector<PT> &p)
{
    int n=SZ(p);
    if(n<2) return 0;
    else if(n==2) return distPoint(p[0],p[1]);//distance between two points
    else
    {
        int i=n-1,j=0,k=1;
        double res=0;
        while(abs(cross(p[j]-p[i],p[k+1]-p[i]) >
                  abs(cross(p[j]-p[i],p[k]-p[i]))))
        {
            k++;
        }
        i=0,j=k;
        while(i<=k && j<n)
        {
            res=max(distPoint(p[i],p[j]),res);
            while(j<n-1 && abs(cross(p[i+1]-p[i],p[j+1]-p[i]) >
                      abs(cross(p[i+1]-p[i],p[j]-p[i]))))
            {
                j++;
                res=max(distPoint(p[i],p[j]),res);
            }
            i++;
        }
        return res;
    }
}

int main()
{
    #ifdef MAHDI
//    Read;
//    Write;
    #endif // MAHDI
    vector<PT> poly,cpoly;PT a;
    int n;
    sf("%d",&n);
    for(int i=0;i<n;i++)
    {
        a.input();
        poly.psb(a);
    }
    ConvexHull(poly,cpoly);
    pf("%.12f\n",polygonDiameter(cpoly));
    return 0;
}
