#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a,b,c,d;
    int aa,bb,cc,dd;
    int m;
    cin>>m;
    while(m--)
    {
        cin>>a>>aa>>b>>bb>>c>>cc>>d>>dd;
        long long kk=100000000;
        string k;
        if(aa<kk)
        {kk=aa;k=a;}
        if(bb<kk)
        {kk=bb;k=b;}
        if(cc<kk)
        {kk=cc;k=c;}
        if(dd<kk)
        {kk=dd;k=d;}
        cout<<"Poor "<<k<<endl;
    }
    
    return 0;
}  