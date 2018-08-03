#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
const int maxn=500000;
char s[maxn];
int ans1,ans2,len,k;
int dfs(int flag)
{
    while(k<len&&s[k]=='C')
    {
        k+=2;
        flag^=1;
    }
    if(k>=len)  return 0;
    if(s[k]=='V')
    {
      k+=2;
      return 1;
    }
    k+=2;
    int x=dfs(flag);
    int y=dfs(flag);
    //cout<<x<<" "<<y<<" "<<flag<<" "<<k<<endl;
    if(flag)  return max(x,y);
    else  return x+y;
}
int main()
{
    while(gets(s))
    {
         ans1=ans2=0;
         len=strlen(s);
         k=0;
         cout<<dfs(0)<<endl;
    }
}
                  
