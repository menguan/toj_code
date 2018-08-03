#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctype.h>
using namespace std;
int t;
char a[20];
char b[20];
int ans;int t1,t2;
int f(char *temp)
{
    int now=1;int ret=0;
    int len=strlen(temp);
    for(int i=0;i<len;i++)
    {
       if(isdigit(temp[i]))
       {
          now=temp[i]-'0';
       }
       else
       {
          if(temp[i]=='m')
          {
             ret+=now*1000;
          }
          else if(temp[i]=='c')
          {
             ret+=now*100;
          }
          else if(temp[i]=='x')
          {
             ret+=now*10;
          }
          else
             ret+=now;
          now=1;
       }
    }
    return ret;
}  
int main()
{
     cin>>t;
     while(t--)
     {
        ans=0;
        cin>>a>>b;
        t1=f(a);
        t2=f(b);
        ans=t1+t2;
        if(ans/1000>0)
        {
           if(ans/1000==1)
             cout<<"m";
           else
             cout<<ans/1000<<"m";
        }
        ans%=1000;
        if(ans/100>0)
        {
           if(ans/100==1)
             cout<<"c";
           else
             cout<<ans/100<<"c";
        }
        ans%=100;
        if(ans/10>0)
        {
           if(ans/10==1)
             cout<<"x";
           else
             cout<<ans/10<<"x";
        }
        ans%=10;
        if(ans>0)
        {
           if(ans==1)
             cout<<"i";
           else
             cout<<ans<<"i";
        }
        cout<<endl;   
     }
}                        
