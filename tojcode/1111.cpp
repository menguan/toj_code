#include<iostream>
#include<cstring>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
const int maxn=1010101010;
int getnum(string s1)
{
    if(s1=="x")
      return maxn;
    int ret=0;int len=s1.length();
    for(int i=0;i<len;i++)
    {
         ret*=10;
         ret+=(s1[i]-'0');
    }
    return ret;
}   
int con[220][220]  ;  
          
int main()
{
    string s;
    memset(con,0,sizeof(con));
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
       for(int j=1;j<i;j++)
       {
           cin>>s;
           con[i][j]=con[j][i]=getnum(s);
       }
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    for(int k=1;k<=n;k++)
    {
         if(con[j][i]+con[i][k]<con[j][k])
           con[j][k]=con[j][i]+con[i][k];
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
       if(con[1][i]>ans)
         ans=con[1][i];
    }
    cout<<ans<<endl;
    //while(1);
}            
                   
                    
    
