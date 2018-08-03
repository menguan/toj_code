#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        bool flag=1;
        double n;
        bool chao=0;
        cin>>n;
        double a,b;
        double us=0,ge=0;
        double aa=0,bb=0;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            if(i==0)
            {
                us+=a;ge+=b;
            }
            else{
                   // cout<<a*ge/b<<endl;
                us+=a*ge/b;
            }
             bb+=b;
        }
       // cout<<us<<endl;
        if(us<ge)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
