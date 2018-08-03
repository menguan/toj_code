#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int x[100001];
int n;
int lowbit(int t)
{
  return t&(-t);
} 
int sum(int end) 
{ 
    int sum = 0; 
    while(end>0) 
    { 
        sum+=x[end]; 
        end-=lowbit(end); 
    } 
    return sum; 
} 
void add(int t,int num) 
{ 
    while(t<=n) 
    { 
          x[t]+=num; 
          t+=lowbit(t); 
    } 
} 
  
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    memset(x,0,sizeof(x));
    int k;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>k;
      add(i,k);
    }
    int op;
    cin>>op;
    while(op--)
    {
      string s;
      int st,en;
      cin>>s;
      if(s=="Inquire")
      {
        cin>>st>>en;
        cout<<sum(en)-sum(st-1)<<endl;
      }
      else if(s=="Add")
      {
        cin>>st>>en;
        add(st,en);
      }
      else if(s=="Delete")
      {
        cin>>st>>en;
        if((sum(st)-sum(st-1)-en)<0)
        add(st,-sum(st)+sum(st-1));
        else
        add(st,-en);
        
      }
    }
  }
}                  
        
    