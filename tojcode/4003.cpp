#include<iostream>
#include<string>
using namespace std;
string f(string st1, string st2)
{
string st;
int a[102000]={0},b[102000]={0};
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
bool g(string a)
{
  int len=a.length();
  int sum=0;
  for(int i=0;i<len;i++)
  {
    sum+=(a[i]-'0');
  }
  if(sum%10)
    return 0;
  else
    return 1;
}      
            
int main()
{
  int t,n,i;
  string a; 
  cin>>t;
  while(t--)
  {
    cin>>a;
    while(1)
    {
      a=f(a,"1");
      if(g(a))
        break;
    }
    cout<<a<<endl;
  }  
}         
  