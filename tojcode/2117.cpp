#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string f(string st1, string st2)
{
string st;
int a[2000]={0},b[2000]={0};
int len1,len2,len,i;
len1=st1.length();
len2=st2.length();
for(i=len1-1;i>=0;i--)
   a[len1-i]=st1[i]-'0';
for(i=len2-1;i>=0;i--)
   b[len2-i]=st2[i]-'0';
len=(len1>len2)?len1:len2;
for (i=1;i<=len;i++)
   a[i]=a[i]+b[i];
for (i=1;i<=len;i++)
   if (a[i]>9)
   {
    a[i+1]+=a[i]/ 10;
    a[i]%=10;
    if (i==len ) len++;
   }
   st="";
   for (i=0;i<len;i++)
    st+=a[len-i]+'0';
   return st;
}
bool flag[10];

bool is(string s)
{
  memset(flag,0,10);
  
  
  
  int len=s.length();
  for(int i=0;i<len;i++)
  {
    int t=s[i]-'0';
    if(flag[t]==1)
      return 0;
    
    flag[t]=1;
  }      
  int t=len;
  memset(flag,0,10);
  
  int now=0;
  int st=s[0]-'0';
  while(t--)
  {
     now=(st+now)%len;
     flag[now]=1;
     st=s[now]-'0';
  }
  for(int i=0;i<len;i++)
  {
    if(flag[i]==0)
      return 0;;
  }
  return 1;
}
int main()
{
  string s;
  int count=1;
  
  while(cin>>s)
  {
    if(s=="0")
      return 0;
      
    while(1)
    {
      if(is(s)==1)
        break;
        
      else
      s=f(s,"1");
    }
    cout<<"Case "<<count++<<": ";
    cout<<s<<endl;
  }
}                                    
     