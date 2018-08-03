#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
class f
{
  public: 
    int father,dis;
}a[30000];


void init(int n)
{
        for(int i=1;i<=n;i++)
        {
                a[i].father=i;
                a[i].dis=0;
        }
}
int find(int n)
{
        int t;
        if(a[n].father==n)  return n;
        t=find(a[n].father);
        a[n].dis+=a[a[n].father].dis;
        return a[n].father=t;
         
}
int main()
{
        int t,n,i,j;
        char c;
        cin>>t;
        while(t--)
        {
                cin>>n;
                init(n);
                while(cin>>c)
                {
                        if(c=='O') 
                                break;
                        if(c=='I')
                        {
                                cin>>i>>j;
                                int d=abs(i-j)%1000;
                                a[i].dis=d;                
                                a[i].father=j;
                        }
                        else 
                        {
                                 
                                cin>>i;
                                find(i);
                                cout<<a[i].dis<<endl;              
                        }
                }
        }
}
