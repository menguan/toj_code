#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<ctype.h>
using namespace std;
map<char,int> x;
map<char,int> y;
int mc[1000],mr[1000];
int main()
{
    int n;char c;
    int num;
    string s;
    cin>>n;
    while(n--)
    {
       cin>>c>>num;
       x[c]=num;
       cin>>num;
       y[c]=num;
    }
    while(cin>>s)
    {
          int ans=0;
          int len=s.length();
          bool flag=1;
          int top=0;
          for(int i=0;i<len;i++)
          {
              if(s[i]==')')
              {
                    if(mc[top-1]!=mr[top]){ cout<<"error"<<endl; flag=0;break;}
                      ans+=mr[top-1]*mr[top]*mc[top];
                      mc[top-1]=mc[top];
                    top--;
              }
              if(isupper(s[i]))
              {
                    top++;
                    mr[top]=x[s[i]];mc[top]=y[s[i]];
              }
          }
          if(flag)
             cout<<ans<<endl;
    }
}                                          
    
