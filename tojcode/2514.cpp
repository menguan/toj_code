#include<iostream>
#include<cstring>
using namespace std;
char a[101],b[101];
int len1;int len2;
int a1[10];
int a2[10];
bool judge()
{
  memset(a1,0,sizeof(a1));
  memset(a2,0,sizeof(a2));
  for(int i=0;i<len1;i++)
  {
    a1[a[i]-'0']=1;
  }
  for(int i=0;i<len2;i++)
  {
    a2[b[i]-'0']=1;
  }
  for(int i=0;i<10;i++)
  {
    if(a1[i]!=a2[i])
      return 0;
  }
  return 1;
}          
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin>>a>>b;
    len1=strlen(a);
    len2=strlen(b);
    bool flag=0;
    if(judge())
    {
      cout<<"friends"<<endl;
    }
    else
    {
      for(int i=0;i<len1-1&&!flag;i++)
      {
        if(a[i]-'0'>0&&a[i+1]-'0'<9)
        {
          a[i]--;
          a[i+1]++;
          if(judge()&&a[0]!='0')
          {
           //cout<<a<<" "<<b<<endl;
            //cout<<"kk1"<<endl;
            flag=1;
          }
          a[i]++;
          a[i+1]--;
        }
        if(a[i+1]-'0'>0&&a[i]-'0'<9)
        {
          a[i+1]--;
          a[i]++;
          if(judge()&&a[0]!='0')
          {
            //cout<<"kk2"<<endl;
            flag=1;
          }
          a[i+1]++;
          a[i]--;
        }
      }    
      for(int i=0;i<len2-1&&!flag;i++)
      {
        if(b[i]-'0'>0&&b[i+1]-'0'<9)
        {
          b[i]--;
          b[i+1]++;
          if(judge()&&b[0]!='0')
          {
            //cout<<"kk3"<<endl;
            flag=1;
          }  
          b[i]++;
          b[i+1]--;
        }
        if(b[i+1]-'0'>0&&b[i]-'0'<9)
        {
          b[i+1]--;
          b[i]++;
          if(judge()&&b[0]!='0')
          {
            //cout<<"kk4"<<endl;
            flag=1;
          }
          b[i+1]++;
          b[i]--;
        }
      }
      if(flag)
        cout<<"almost friends"<<endl;
      else
        cout<<"nothing"<<endl;
    }  
  }
}                    